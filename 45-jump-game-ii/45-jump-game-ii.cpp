class Solution {
public:
    /*Recursion
    int helper(int idx, vector<int>& nums)
    {
        if(idx>=nums.size()-1)
            return 0;
        int jumps=1001;
        for(int i=1;i<=nums[idx];i++)
        {
            jumps=min(jumps,(1+ helper(idx+i,nums)));
        }
        return jumps;
        Time Complexity : O(N!). At each index i we have N-i choices and we recursively explore each of them till end. So we require O(N*(N-1)*(N-2)...1) = O(N!).
Space Complexity : O(N)
    }
    */
    
    int helper(int idx, vector<int>& nums,vector<int>& dp)
    {
        if(idx>=nums.size()-1)
            return 0;
        if(dp[idx]!=1001)
            return dp[idx];
        
        for(int i=1;i<=nums[idx];i++)
        {
            dp[idx]=min(dp[idx],(1+ helper(idx+i,nums,dp)));
        }
        cout<<dp[idx]<<endl;
        return dp[idx];
    }
    
    int jump(vector<int>& nums) {
       // vector<int> dp(nums.size(),1001);
        //return helper(0,nums,dp);
        if(nums.size()==1)return 0;
        int current=nums[0];
        int farthest=nums[0];
        int jumps=1;
        
        for(int i=1;i<size(nums);i++)
        {
            if(i==nums.size()-1)
            {
                //For this test case [1,2] 
                return jumps;
            }
               
            
            farthest=max(farthest,i+nums[i]);
            current--;
            if(current==0)
            {
                current=farthest-i;
                jumps++;
            }
        }
        return jumps;
        
        
    }
};