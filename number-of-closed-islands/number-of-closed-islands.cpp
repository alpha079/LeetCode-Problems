class Solution {
public:
    
    //TC:- O(M*N)
    //SC:- O(M*N)
    
    bool dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& vis,int& ans)
    {
        if(i<0 ||j<0 || i>=grid.size() || j>=grid[0].size())
        {
           // cout<<i<<" "<<j<<endl;
            return false;
        }
          
        if(grid[i][j]==1 || vis[i][j]==true)
        {
            
            return true;
        }
         vis[i][j]=true; 
        ans++;
        //cout<<ans<<endl;
        bool d1=dfs(grid,i+1,j,vis,ans);
        bool d2=dfs(grid,i,j+1,vis,ans);
        bool d3=dfs(grid,i-1,j,vis,ans);
        bool d4=dfs(grid,i,j-1,vis,ans);
        return d1 && d2 && d3 && d4; 
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int m=grid[0].size();
        int res=0;
        int ans;
        int ans1=0;
        vector<vector<bool>> vis(n,vector<bool>(m, false));
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                ans=0;
                if(grid[i][j]==0 and !vis[i][j])
                {
                    
                    res+=dfs(grid,i,j,vis,ans) ? 1:0;
                    
                   ans1=max(ans,ans1);
                }
            }
        } 
          cout<<ans1;  
        return res;
        
    }
};
