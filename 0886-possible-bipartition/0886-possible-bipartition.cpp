class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int> > G(n+1, vector<int>());
        for(auto &dis: dislikes){
            G[dis[0]].push_back(dis[1]);
        }
        
        vector<bool> isVisited(n+1, false);
        queue<int> q;
        for(int i = 1; i < n+1; i++){
            if(isVisited[i])
                continue;

            vector<int> color(n+1, -1);
            q.push(i);
            color[i] = 1;

            while(!q.empty()){
                auto top = q.front();
                if(isVisited[top]){
                    q.pop();
                    continue;
                }
                for(auto to: G[top]){
                    if(color[to] == color[top])
                        return false;
                    color[to] = (color[top]+1) % 2;
                    q.push(to);
                }
                isVisited[top] = true;
                q.pop();
            }
        }
        return true;
    }
};