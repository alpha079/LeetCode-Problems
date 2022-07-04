class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i+1][j+1]=mat[i][j];
            }
        }
        
         for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                int val=dp[i][j];
                if(val>dp[i-1][j] and val>dp[i][j-1] and val>dp[i+1][j] and val>dp[i][j+1])
                {
                    return {i-1,j-1};
                }
            }
        }
        return {};
    }
};