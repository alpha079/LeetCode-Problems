class Solution {
public:
    
    //Basic Approach using backtracking will be, we can maintain a visited vector, 
    // which will keep track of the element visited before we backtrack
    //Time Complexity: O(N! * N)
//Auxiliary Space : O(N! * N)
    void solve(vector<int>& num,vector<vector<int>>& res, vector<int>& temp,vector<bool>& vis)
        
    {
        if(temp.size()==num.size())
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=0;i<num.size();i++)
        {
            if(vis[i]==true)continue;
            
            if(i and !vis[i-1] and num[i]==num[i-1])
                continue;
            vis[i]=true;
            temp.push_back(num[i]);
            solve(num,res,temp,vis);
            temp.pop_back();
            vis[i]=false;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(nums.size(),false);
        
        solve(nums,res,temp,vis);
        return res;
        
    }
};