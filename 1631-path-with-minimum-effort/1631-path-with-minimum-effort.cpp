typedef pair<int, vector<int>> p;
class Solution {
public:
    struct comp{
        bool operator()(p const& p1, p const& p2){
            return p1.first > p2.first;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> costs(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), 0));
        
        costs[0][0] = 0;
        priority_queue<p, vector<p>, comp> pq;
        
        pq.push(make_pair(0, vector<int>{0, 0}));
        
        while(!pq.empty()){
            // get the top of the pq
            p node = pq.top();
            pq.pop();
            
            int x1 = node.second[0], y1 = node.second[1];
            
            // mark visited
            visited[y1][x1] = 1;
            
            // find its edges
            vector<vector<int>> edges = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            // Iterate through the edges
            for(vector<int> edge : edges){
                int y = y1+edge[1], x = x1+edge[0];
                
                // If out of range or already visited, continue
                if(x < 0 || y < 0 || x >= heights[0].size() || y >= heights.size() || visited[y][x] == 1){
                    continue;
                }
                
                // If not visited, check for effort update and push back the node
                int curr_eff = abs(heights[y][x] - heights[y1][x1]);
                int curr_cost = max(curr_eff, costs[y1][x1]);
                
                if(curr_cost < costs[y][x]){
                    costs[y][x] = curr_cost;
                    pq.push(make_pair(costs[y][x], vector<int>{x, y}));
                }
            }
            
            // Check if destination already visited, if yes then break
            if(visited[heights.size()-1][heights[0].size()-1]) break;
            
        }
        
        return costs[heights.size()-1][heights[0].size()-1];
        
    }
};