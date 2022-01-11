
/* Solution 2:Using DP 

dp[k][i] = max(dp[k][i-1], prices[i] - prices[j] + dp[k-1][j-1]), j=[0..i-1]

For k transactions, on i-th day,if we don't trade then the profit is same as previous day dp[k, i-1];
and if we bought the share on j-th day where j=[0..i-1], then sell the share on i-th day then the profit is
prices[i] - prices[j] + dp[k-1, j-1].
Actually j can be i as well. When j is i, the one more extra item prices[i] - prices[j] + dp[k-1, j] = dp[k-1, i] looks like we just lose one chance of transaction.
*/

//TC:- O(k*N)  Space:- O(k*N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(3,vector<int>(prices.size(),0));
        
        for(int k=1;k<=2;k++)
        {
            int minprice=prices[0];
            for(int i=1;i<prices.size();i++)
            {
                minprice=min(minprice,prices[i]-dp[k-1][i-1]);
                dp[k][i]=max(dp[k][i-1],prices[i]-minprice);
            }
        }
        return dp[2][prices.size()-1];
        
    }
};
