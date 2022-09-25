class Solution {
public:
    // DP Approach - Space Optimized
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        // swap it to ensure n > m
        if (n < m) {
            // or you can call findLength(nums2, nums1); 
            swap(nums1, nums2);
            swap(n, m);
        }
        // dp records current dp state
        // dp2 records the previous dp state
        vector<int> dp(n + 1), dp2(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    // extend from the previous dp state
                    dp[j] = dp2[j - 1] + 1; 
                } else {
                    // reset to 0
                    dp[j] = 0;
                }
                // record the max length
                ans = max(ans, dp[j]);
            }
            // the current state now becomes the previous state for next round
            dp2 = dp;
        }
        return ans;
    }
};