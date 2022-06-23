//Time Complexity : O(NM)
//Space Complexity : O(NM)

//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/1151423/C%2B%2B-Optimization-from-Brute-Force-to-DP-or-Easy-Solution-w-Explanation

class Solution {
public:
     int DIR[5] = {0, 1, 0, -1, 0};
      vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix, int i, int j)
    {
        if(dp[i][j])
        {
            return dp[i][j];
        }
        dp[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int newX= i + DIR[k];
            int newY= j+ DIR[k+1];
            if(newX<0 || newY<0 || newX>=size(matrix) | newY>=size(matrix[0]) || matrix[newX][newY]<=matrix[i][j])continue;
            dp[i][j]=max(dp[i][j],1+solve(matrix,newX,newY));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int maxPath=1;
        int row=matrix.size();
        int col=matrix[0].size();
        dp.resize(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                maxPath=max(maxPath,solve(matrix,i,j));
            }
        }
        return maxPath;
    }
};