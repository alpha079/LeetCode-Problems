class Solution {
public:
    
 /*   int helper(vector<vector<int>>& grid, int row, int col,vector<vector<int>>& dp)
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
    */
    int minPathSum(vector<vector<int>>& grid) {
         const int INF= 1e9 + 5;
         int row = grid.size(), col = grid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 and j==0)
                    dp[i][j]=grid[i][j];
                else{
                    dp[i][j]=grid[i][j] + min((i==0?INF:dp[i-1][j]),(j==0?INF:dp[i][j-1]));
                }
            }
        }
        return dp[row-1][col-1];
        //TC:- O(M*N)
        //SC: O(M*N)
        
        
    }
};