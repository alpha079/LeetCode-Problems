class Solution {
public:
    
    //Basic Approach using backtracking will be, we can maintain a visited vector, 
    // which will keep track of the element visited before we backtrack
    //Time Complexity: O(N! * N)
//Auxiliary Space : O(N! * N)
    
    bool checkDuplicates(int begin, int i, vector<int>& num)
    {
        for(int k=begin;k<i;k++)
        {
            if(num[k]==num[i])
                return false;
            
        }
        return true;
    }
    void solve(vector<int>& num,vector<vector<int>>& res, int begin)
        
    {
        if(begin==num.size()-1)
        {
            res.push_back(num);
            return;
        }
        
        for(int i=begin;i<num.size();i++)
        {
            if((num[begin]!=num[i] || i==begin) and checkDuplicates(begin,i,num)) 
            {
                swap(num[begin],num[i]);
                solve(num,res,begin+1);
                swap(num[begin],num[i]);
            }
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        //vector<int> temp;
        //vector<bool> vis(nums.size(),false);
        
        solve(nums,res,0);
        return res;
        
    }
};