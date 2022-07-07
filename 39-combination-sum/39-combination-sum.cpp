class Solution {
public:
    
    //The worst-case time complexity will be 2^Target. Think if we have 1 in the list and the target is 7. You have to make 7 branches to the bottom at least, to find the combination with 1. so the height of the tree would be T and the decisions can be two at a time.
    //Time:- O(2^N) where N=target
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