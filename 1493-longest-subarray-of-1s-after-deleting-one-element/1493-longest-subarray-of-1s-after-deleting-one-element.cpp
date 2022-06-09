class Solution {
public:

    int longestSubarray(vector<int>& nums) {
        if(nums.size()==0)return 0;

        vector<int> dp;
        int cnt=0;
        nums.push_back(0);
        for(auto it: nums)
        {
            if(it==1)
            {
                cnt++;
            }
            else{
                dp.push_back(cnt);
                cnt=0;
            }
        }
        if(dp.size()==1)
            return dp[0]-1;
        int ans=0;
        for(int i=0;i<dp.size()-1;i++)
        {
            ans=max(ans,dp[i]+dp[i+1]);
        }
        return ans;
    }
};