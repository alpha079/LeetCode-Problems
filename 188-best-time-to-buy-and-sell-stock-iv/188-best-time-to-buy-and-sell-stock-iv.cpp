class Solution {
public:
    
    //TC:-  //O(k*n^2) time complexity
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
    	if(n==0 || n==1)return 0;

    	if(k>n/2)
    	{

    		int res=0;
    		for(int i=1;i<n;i++)
    		{
    			if(prices[i]-prices[i-1]>0)
    				res+=prices[i]-prices[i-1];
    		}
    		return res;
    	}
     //perform the DP algor for K transactions
    	vector<vector<int>> dp(k+1, vector<int>(prices.size()));

    	for(int i=1;i<=k;i++)  //O(k)
    	{

    		for(int j=1;j<n;j++)   //O(n)
    		{
    			int sell=0;
    			int not_sell=dp[i][j-1];

    			for(int m=0;m<j;m++)    //O(m) because for worst case m==n-1
    			{
    				sell=max(sell,prices[j]-prices[m]+dp[i-1][m]);
    			}
    			dp[i][j]=max(not_sell,sell);
    		}
    	}
    	return dp[k][n-1];
    }
};