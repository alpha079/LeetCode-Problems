
//TC:- O(M*N)
//SC:- O(M*N)
  class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        
          vector<vector<int>> dp(row, vector<int> (col, -1));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 and j==0) dp[i][j]=1;
                
                else if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else{
                    
                    int left=0,up=0;
                    //left for col, up for row
                    if(i>0)up+=dp[i-1][j];
                    if(j>0)left+=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[row-1][col-1];
        
    }
};