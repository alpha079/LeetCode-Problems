//Time: O(2 * m^2), where m <= 10^3
//Space: O(m^2)

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, vector<int>& mul,int idx,int start)
    {
        if(idx==mul.size())
            return 0;
        if(dp[start][idx]!=INT_MIN)
            return dp[start][idx];
        int left=solve(nums,mul,idx+1,start+1)+nums[start]*mul[idx];
        int right=solve(nums,mul,idx+1,start)+nums[nums.size()-1-(idx-start)]*mul[idx];
        //end=nums.size()-1-(idx-start);
        return dp[start][idx]=max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) 
    {
        int m=mul.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return solve(nums,mul,0,0);
    }
};
