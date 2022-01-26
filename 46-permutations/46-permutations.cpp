class Solution {
public:
    //TC:(N*N!)
    //SC:- O(1)
    void solve(vector<int>& num, vector<vector<int>>& res,int low, int high)
    {
        if(low==high)
        {
            res.push_back(num);
            return;
            
        }
        else{
            for(int i=low;i<=high;i++)
            {
                swap(num[low],num[i]);
                solve(num,res,low+1,high);
                swap(num[low],num[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> res;
        
        solve(nums,res,0,nums.size()-1);
        
        return res;
        
    }
};