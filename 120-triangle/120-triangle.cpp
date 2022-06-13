class Solution {
public:
    int helper(int src, int des,vector<vector<int>>& num,vector<vector<int>>& dp )
        
    {
        if(src==num.size()-1)
        {
            return num[src][des];
        }
        if(dp[src][des]!=-1)
        {
            return dp[src][des];
        }
        int down=num[src][des] + helper(src+1,des,num,dp);
        int diagonal=num[src][des] + helper(src+1,des+1,num,dp);
        
        return dp[src][des]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        
       vector<vector<int>> dp(n, vector<int> (n,-1));
        
        return helper(0,0,triangle,dp);
        
    }
};