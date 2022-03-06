//https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/1824108/Recursion-with-memo-(with-explanation-)

class Solution {
public:
    int mod = pow(10,9)+7;
    int totalWays(long unpicked, long undelivered,vector<vector<long>>&dp){
        if(undelivered < unpicked || undelivered < 0 || unpicked < 0)
            return 0;
        if(dp[unpicked][undelivered] == 0)
            dp[unpicked][undelivered] = (unpicked*totalWays(unpicked-1,undelivered,dp))%mod
            + ((undelivered - unpicked)*totalWays(unpicked,undelivered-1,dp))%mod;
        return dp[unpicked][undelivered]%mod;
    }
    int countOrders(int n) {
        vector<vector<long>>dp(n+1,vector<long>(n+1,0));
        dp[0][0] = 1;
        return totalWays(n,n,dp);
    }
};