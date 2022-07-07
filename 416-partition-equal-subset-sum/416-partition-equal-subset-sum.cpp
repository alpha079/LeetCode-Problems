class Solution {
public:
    int dp[202][10002];
    
    bool helper(vector<int>& nums, int sum, int i=0)
    {
        if(sum==0)return true;
        if(i>=size(nums) || sum<0)return false;
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        return dp[i][sum]=helper(nums,sum-nums[i],i+1) || helper(nums,sum,i+1);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total&1)return false;
         memset(dp,-1,sizeof(dp));
        return helper(nums,total/2);
        
    }
};