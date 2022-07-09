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
                current=farthest-i; //this is important.
                jumps++;
            }
        }
        return jumps;
        
        /*
        This problem has a nice BFS structure. Let's illustrate it using the example nums = [2, 3, 1, 1, 4] in the problem statement. We are initially at position 0. Then we can move at most nums[0] steps from it. So, after one move, we may reach nums[1] = 3 or nums[2] = 1. So these nodes are reachable in 1 move. From these nodes, we can further move to nums[3] = 1 and nums[4] = 4. Now you can see that the target nums[4] = 4 is reachable in 2 moves.

Putting these into codes, we keep two pointers start and end that record the current range of the starting nodes. Each time after we make a move, update start to be end + 1 and end to be the farthest index that can be reached in 1 move from the current [start, end].

To get an accepted solution, it is important to handle all the edge cases. And the following codes handle all of them in a unified way without using the unclean if statements :-)
        */
    }
};