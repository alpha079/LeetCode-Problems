class Solution {
public:
    
       
    //TC: O(n(2 ^ n)). 
//For every index i two recursive cases originate, So Time Complexity is O(2^n). If we include the time taken to copy the subset vector into the res vector the time taken will be equal to the size of the subset vector.
    //Blog for TC:- https://medium.com/@vasanths294/permutation-combination-subset-time-complexity-eca924e00071
    void helper(vector<int>& nums, int idx,vector<int>& ans, vector<vector<int>>& res)
    {
        if(idx==nums.size())
        {
            res.push_back(ans); //Copy vector takes O(N) time max for full length
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