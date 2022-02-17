class Solution {
public:
    
    //Time:- O(2^N)
    //[2,7,6,3,5,1] , 9
    //Without sorting failing on this test case
    void helper(vector<int>& num,int target,vector<vector<int>>& res,vector<int>& ans,int begin)
    {
        if(target==0)
        {
            res.push_back(ans);
            return;
        }
        for(int i=begin;i<num.size()&& target>=num[i];i++)
        {
            ans.push_back(num[i]);
            helper(num,target-num[i],res,ans,i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        
        helper(candidates,target,res,ans,0);
        return res;
        
    }
};