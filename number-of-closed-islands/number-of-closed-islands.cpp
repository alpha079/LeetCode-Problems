class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& vis)
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
        bool d1=dfs(grid,i+1,j,vis);
        bool d2=dfs(grid,i,j+1,vis);
        bool d3=dfs(grid,i-1,j,vis);
        bool d4=dfs(grid,i,j-1,vis);
        return d1 && d2 && d3 && d4; 
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int m=grid[0].size();
        int res=0;
        vector<vector<bool>> vis(n,vector<bool>(m, false));
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(grid[i][j]==0 and !vis[i][j])
                {
                    cout<<i<<" "<<j<<endl;
                    res+=dfs(grid,i,j,vis) ? 1:0;
                }
            }
        } 
            
        return res;
        
    }
};