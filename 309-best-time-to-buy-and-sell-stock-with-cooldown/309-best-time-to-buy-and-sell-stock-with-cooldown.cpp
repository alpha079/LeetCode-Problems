class Solution {
public:
    //Time:O(N)
    int dp[10001][2]={0};
   
    int count(int idx,int buy,vector<int>& prices)
    {
        if(idx>=prices.size())
            return 0;
        if(dp[idx][buy]!=0)
            return dp[idx][buy];
        if(buy==0)
        {
            int buyStock=count(idx+1,1,prices)-prices[idx];
            int skip=count(idx+1,0,prices);
            dp[idx][buy]=max(skip,buyStock);
        }
        else{
            int sellStock=count(idx+2,0,prices)+prices[idx];
            int skip=count(idx+1,1,prices);
            dp[idx][buy]=max(skip,sellStock);
            
        }
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        
     return count(0,0,prices);
        
    }
};