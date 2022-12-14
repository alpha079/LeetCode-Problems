class Solution {
public:
    int dp[105];
    int solve(vector<int> num, int index)
   {
   	if(index>=num.size()) return 0; //return 0 to previous function call
    
        if(dp[index]!=-1)return dp[index];

   	 int include=num[index] + solve(num,index+2);

   	 int exclude= solve(num,index+1);

   	 return dp[index]=max(include,exclude);
   }
    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        
 	return solve(nums,0); //start from 0 index
        
    }
};