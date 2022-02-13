class Solution {
public:
    //TC:- O(N*2^N) + O(Nlogn) for sorting
    void helper(vector<int>& nums, int idx,vector<vector<int>>& res,vector<int>& ans)
    {
         res.push_back(ans);
        for(int i=idx;i<nums.size();i++)
        {
            if(i==idx || nums[i]!=nums[i-1])
            {
                ans.push_back(nums[i]);
                  helper(nums,i+1,res,ans);
                  ans.pop_back();
            }
          
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums,0,res,ans);
        return res;
        
        
    }
};