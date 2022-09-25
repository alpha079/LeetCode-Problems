class Solution {
public:
   vector<vector<int>>dp;
 //https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/1324737/Optimization-from-Brute-Force-to-DP-to-Space-Optimized-DP-Explained! 
    
    int helper(vector<int>& A, vector<int>& B, int i, int j, int& res)
    {
        if(i>=A.size() || j>=B.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int len=0;
        if(A[i]==B[j])
        {
             len=1+helper(A,B,i+1,j+1,res);
            res=max(res,len);
            
        }
        
        helper(A,B,i+1,j,res);
        helper(A,B,i,j+1,res);
        return dp[i][j]=len;   }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(size(nums1), vector<int>(size(nums2), -1));
        int res=0;
     helper(nums1,nums2,0,0,res);
    return res;   
        
     /*   Time Complexity : O(M*N), where M is size of A and N is size of B. We have 3 choices at each recursion and max recursion depth is M+N.
Space Complexity : O(M*N), max depth of recursive stack.
        */
    }
};