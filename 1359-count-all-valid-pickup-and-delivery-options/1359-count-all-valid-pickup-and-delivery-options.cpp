//https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/1824108/Recursion-with-memo-(with-explanation-)

class Solution {
public:
    int mod = pow(10,9)+7;
    
    long long totalWays(int pickup, int deliver, vector<vector<long>>&dp)
    {
      
        if(deliver<pickup || pickup<0 || deliver<0)
        {
            return 0;
        }
        if(dp[pickup][deliver]==0)
        {
             dp[pickup][deliver]=pickup*totalWays(pickup-1,deliver,dp)%mod+(deliver-pickup)*totalWays(pickup,deliver-1,dp)%mod;
        }
       
        
        return dp[pickup][deliver]%mod;
    }
    int countOrders(int n) {
        vector<vector<long>>dp(n+1,vector<long>(n+1,0));
        dp[0][0] = 1;
        return totalWays(n,n,dp);
    }
};