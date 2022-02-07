class Solution {
public:
    
    void helper(vector<int>& nums, int idx,vector<int>& ans, vector<vector<int>>& res)
    {
        if(idx==nums.size())
        {
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        helper(nums,idx+1,ans,res);
        ans.pop_back();
        helper(nums,idx+1,ans,res);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums,0,ans,res);
        
        return res;
        
    }
};