class Solution {
public:
  void helper(vector<int>& nums, int idx,vector<int>& ans, vector<vector<int>>& res)
    {
       res.push_back(ans);
      for(int i=idx;i<nums.size();i++)
      {
          ans.push_back(nums[i]);
          helper(nums,i+1,ans,res);
          ans.pop_back();
          
      }
      
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums,0,ans,res);
        
        return res;
        
    }
};
