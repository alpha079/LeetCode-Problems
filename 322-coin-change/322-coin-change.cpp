class Solution {
public:
    //https://leetcode.com/problems/coin-change/discuss/2058536/Recursion-greatermemoisation-greater2Dtabulation-greater1Dtabulation
    //Exponential Time complexity
    //O(amount*N) where N is size of the array 
    int helper(vector<int>& coins,int n, int target,vector<vector<int>>& dp)
    {
        if(n==0 || target==0)
            return (target==0?dp[target][n]=0 :dp[target][n]=1e9);
        if(dp[target][n]!=-1)
        {
            return dp[target][n];
        }
        if(coins[n-1]>target)
            return dp[target][n]=helper(coins,n-1,target,dp);
        return dp[target][n]=min(helper(coins,n,target-coins[n-1],dp)+1,helper(coins,n-1,target,dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
         vector<vector<int>> dp(amount+1, vector<int>(n+1,-1));
        int ans= helper(coins,n,amount,dp);
        return (ans==1e9 ?-1: ans);
    }
};