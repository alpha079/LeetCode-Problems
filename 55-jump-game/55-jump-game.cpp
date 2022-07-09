class Solution {
public:
    
   /*Recursion 
    bool canJump(vector<int>& nums, int idx)
    {
        if(idx==nums.size()-1)
            return true;
        
        int maxjump=idx+nums[idx];
        for(int i=idx+1;i<=maxjump;i++)
        {
            if(canJump(nums,i))
                return true;
        }
        return false;
    }
    */
    
    //Memoization
    bool canJump(vector <int> nums, int curr, vector <bool>& dp) {
        if (curr == nums.size() - 1) {
            return true;
        }
        if (dp[curr]) {
            return dp[curr];
        }
        int maxjump=curr+nums[curr];
        for(int i=curr+1;i<=maxjump;i++)
        {
            if(canJump(nums,i,dp))
                return dp[curr]=true;
        }
        dp[curr] = false;
        return dp[curr];
    }
    
    // O(N) Appraoch
    bool canJump(vector<int>& nums) {
        //vector<bool> dp(nums.size(),false);
        // return canJump(nums,0);
      // return canJump(nums,0,dp);
        
        int reachable=0;
        for(int i=0;i<size(nums);i++)
        {
            if(reachable<i)
                return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};