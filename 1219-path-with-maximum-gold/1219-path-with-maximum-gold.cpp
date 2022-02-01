class Solution {
public:
    //Time: O(k * 4 ^ k + m * n - k), space: O(m * n), where k = number of gold cells, m = grid.length, n = grid[0].length.
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        if(i<0 ||i>=m || j<0 ||j>=n || grid[i][j]==0)
        {
            return 0;
        }
        int value=grid[i][j];
        grid[i][j]=0;
        int maxGold=0;
        int DIR[5] = {0, 1, 0, -1, 0};
        for(int k=0;k<4;k++ )
        {
            maxGold=max(maxGold,dfs(grid,i+DIR[k],j+DIR[k+1],m,n));
        }
        grid[i][j]=value;
        return value+maxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxGold=0;
         int m = grid.size(), n = grid[0].size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                maxGold=max(maxGold,dfs(grid,i,j,m,n));
            }
        }
        return maxGold;
        
    }
};