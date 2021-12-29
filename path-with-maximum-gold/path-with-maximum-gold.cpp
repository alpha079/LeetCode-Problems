class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        if(i<0 || j<0 || i>=m ||j>=n)
            return false;
        return true;
    }
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int helper(vector<vector<int>>& grid, int i, int j)
    {
        if(!isValid(i,j,grid.size(), grid[0].size()) || grid[i][j]==0)
            return 0;
        int temp=grid[i][j];
        grid[i][j]=0;
        int mx=0;
        for(int k=0;k<4;k++)
        {
            mx=max(mx,helper(grid,i+dx[k],j+dy[k]));
            
        }
        grid[i][j]=temp;
        return mx+temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
                    ans=max(ans,helper(grid,i,j));
                }
            }
        }
        return ans;
        
    }
};