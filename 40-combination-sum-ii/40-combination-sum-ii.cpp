class Solution {
public:
    
    //TC:- O(k * 2 ^ n) is the time complexity of Combination Sum II:
    //TC Discussed here :- https://leetcode.com/problems/combination-sum/discuss/16634/If-asked-to-discuss-the-time-complexity-of-your-solution-what-would-you-say
    void solve(vector<int>& num, int target,vector<vector<int>>& res,vector<int>& mid, int begin)
    {
        if(target==0)
        {
            res.push_back(mid);
            return;
        }
        for(int i=begin;i!=num.size() && target>=num[i];++i)
        {
            if(i==begin || num[i]!=num[i-1])
            {
                mid.push_back(num[i]);
                solve(num,target-num[i],res,mid,i+1);
                 mid.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>> res;
        vector<int> mid;
        solve(candidates,target,res,mid,0);
        return res;
        
    }
};