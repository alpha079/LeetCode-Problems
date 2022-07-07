class Solution {
public:
    
    int helper(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& dp)
    {
        if(row==0 and col==0)
            return grid[row][col];
        if(row<0 || col<0)
            return INT_MAX;
        if(dp[row][col] != -1)
        return dp[row][col];
        int left=helper(grid,row-1,col,dp);
        int right=helper(grid,row,col-1,dp);
        return dp[row][col]=min(left,right)+ grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
         int row = grid.size(), col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return helper(grid,row-1,col-1,dp);
        
        
    }
};