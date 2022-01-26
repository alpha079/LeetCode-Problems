class Solution {
public:
    
    //Generate all Permutation using Recursion + Backtracking
    //(n*n!).. There are n! permutations of an array
    
    
    void solve(vector<int>& nums,vector<vector<int>>& res, vector<int>& temp,vector<int> freq)
    {
        if(temp.size()==nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int it=0;it<nums.size();it++)
        {
           
            if(!freq[it])
            {
                freq[it]=1;
                temp.push_back(nums[it]);
                solve(nums,res,temp,freq);
                freq[it]=0;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> freq(nums.size(),0);
        
       
        vector<vector<int>> res;
        vector<int> temp;
        
        solve(nums,res,temp,freq);
        return res;
        
    }
};