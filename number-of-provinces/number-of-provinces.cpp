class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int i)
    {
        vis[i]=true;
        for(int k=0;k<isConnected.size();k++)
        {
            if(k!=i and !vis[k] and isConnected[i][k]==1)
                dfs(isConnected,vis,k);
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        if(n==0)return 0;
        int cnt=0;
        
        vector<bool> vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(isConnected,vis,i);
                cnt++;
            }
        }
        return cnt;
        
    }
};