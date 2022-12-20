class Solution {
public:
    void dfs(int i, vector<int>& vis, vector<vector<int>>& rooms)
    {
        vis[i]=1;
        
        for(int it: rooms[i])
        {
            if(vis[it]==0)
            {
                dfs(it,vis,rooms);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        
        vector<int> vis(n,0);
        
        dfs(0,vis,rooms);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
                return false;
        }
        return true;
        
    }
};