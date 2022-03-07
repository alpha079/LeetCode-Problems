//https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/516940/Simple-Java-DP

class Solution {
public:
    //TC:- O(N)
    int countOrders(int n) {
        long dp[501]={0};
        dp[1]=1L;
        dp[2]=6L;
        int mod = pow(10,9)+7;
        for(int i=3;i<=n;i++)
        {
            int spaceCount=2*(i-1)+1;
            long val=(spaceCount*(spaceCount+1)/2)%mod;
            dp[i]=(dp[i-1]*val)%mod;
        }
        return dp[n]%mod;
    }
};