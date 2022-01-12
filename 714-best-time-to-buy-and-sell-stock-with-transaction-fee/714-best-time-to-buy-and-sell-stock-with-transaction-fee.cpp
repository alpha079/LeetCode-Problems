class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
         int n = prices.size();
   // int dp[n] = {0}; //maximum profit
        vector<int> dp(n,0);
        int profit=dp[0]-prices[0]-fee;
        
        for(int i=1;i<n;i++)
        {
            dp[i]=max(dp[i-1],profit+prices[i]);  //do nothing or sell
            profit=max(profit,dp[i]-prices[i]-fee);
        }
        return dp[n-1];
        
    }
};