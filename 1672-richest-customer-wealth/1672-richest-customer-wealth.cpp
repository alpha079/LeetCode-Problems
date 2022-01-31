class Solution {
public:
    int maximumWealth(vector<vector<int>>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            sum=accumulate(nums[i].begin(),nums[i].end(),0);  //caculates sum of each row
            ans=max(sum,ans);  //stores the maximum sum 
        }
        return ans;
        
    }
};