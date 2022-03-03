class Solution {    
   
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)   return 0;
        vector<int> dp(A.size(), 0);
        int res = 0;
        for (int i = 2; i < A.size(); i ++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                dp[i] = dp[i - 1] + 1;
            res += dp[i];
            cout<<dp[i]<<endl;
        }
        return res;
    }
};