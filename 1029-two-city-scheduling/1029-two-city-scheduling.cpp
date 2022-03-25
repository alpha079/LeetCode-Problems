class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        int w=costs[0].size();
        int result=0;
      priority_queue<pair<int, int>> p;
        for(int i=0;i<n;i++)
        {
         p.push(make_pair(costs[i][0]-costs[i][1],i));
        }
        
        for(int i=0;i<n/2;i++)
        {
            result+=costs[p.top().second][1];
            p.pop();
        }
        for(int i=0;i<n/2;i++)
        {
            result+=costs[p.top().second][0];p.pop();
        }
        
        return result;
    }
};
