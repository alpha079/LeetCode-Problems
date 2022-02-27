class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        
        vector<vector<int>> graph(n);
        
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
            {
                graph[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({0,headID});
        int res=0;
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                auto time=q.front().first;
                auto node=q.front().second;
                q.pop();
                
                if(graph[node].size())
                {
                    for(auto it: graph[node])
                    {
                        q.push({time+informTime[node],it});
                    }
                }
                else{
                    res=max(res,time);
                }
                
            }
        }
        return res;
        
    }
};