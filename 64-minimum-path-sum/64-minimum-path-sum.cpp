class Solution {
public:
    
    //TC:- O(row*COl)
    //SC:- O(row*col)
  
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, 0));
   
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=grid[i][j];
            }
            else{
                
                int up=grid[i][j];
                if(i>0)up+=dp[i-1][j];
                else up=1e8;
                
                int left=grid[i][j];
                if(j>0)left+=dp[i][j-1];
                else left=1e8;
                
                dp[i][j]=min(left,up);
            }
        }
    }
    return dp[row-1][col-1];
}
};