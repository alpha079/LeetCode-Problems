class Solution {
public:
	bool helper(string s1, string s2, string s3,int l1,int l2,int l3,vector<vector<int>> &dp){
		if(l1 <= 0 && l2 <= 0 && l3 <= 0)return true;
		// if(l1 <= 0 || l2 <= 0 || l3 <= 0)return false;

		if(l1 > 0 && l2 > 0 && dp[l1][l2] != -1){
			return dp[l1][l2];
		}

		if(l1 > 0 && s1[l1-1] == s3[l3-1] && l2 > 0 && s2[l2-1] == s3[l3-1]){
			return dp[l1][l2] = (helper(s1,s2,s3,l1-1,l2,l3-1,dp) || helper(s1,s2,s3,l1,l2-1,l3-1,dp));
		}
		if(l1 > 0 && s1[l1-1] == s3[l3-1]){
			return helper(s1,s2,s3,l1-1,l2,l3-1,dp);
		}
		if(l2 > 0 && s2[l2-1] == s3[l3-1]){
			return helper(s1,s2,s3,l1,l2-1,l3-1,dp);
		}
		return false;
	}
	bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.length() , l2 =s2.length() , l3 = s3.length();
		if(l1+l2 != l3)return false;
		vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));

		return helper(s1,s2,s3,l1,l2,l3,dp);
	}
};