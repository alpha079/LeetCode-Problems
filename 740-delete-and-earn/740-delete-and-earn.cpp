//https://leetcode.com/problems/delete-and-earn/discuss/1723372/C%2B%2B-solution-brute-force-(TLE)-greater-top-down-dp-greater-bottom-dp

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxValue = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            maxValue = max(maxValue, nums[i]);
        }
        
        vector<int> values(maxValue + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            values[nums[i]] += nums[i];
        }
        
        // Based on the description, the valid elements are 1, 2, .. maxValue.
        // Therefore, values[0] is not used.
        
        // memo[i] is the max points you can get from values[1..i]
        vector<int> memo(values.size(), -1);
        
        // Although 0 is not an valid value in nums, I need it to use the idea
        // of houser robber to solve this question.
        // Therefore, I use memo[0] = 0 as a base case.
        // Base Case 0:
        memo[0] = 0;
        
        memo[1] = values[1];
        if (values.size() == 2) {
            // Base Case 1:
            // When there is only one element in values,
            // values[1] is the max points you can get.
            return memo[1];
        }
        
        // findMaxPoints(i) returns the max points you can get from values[1..i].
        return findMaxPoints(values, memo, values.size() - 1);
    }
    
private:
    int findMaxPoints(vector<int>& values, vector<int>& memo, int i) {
        if (memo[i] != -1) {
            return memo[i];
        }
        
        // findMaxPoints(values, i - 1) means you don't take values[i].
        // findMaxPoints(values, i - 2) + values[i] means you take values[i].
        // Then, the max points you can get is the larger one of the two cases.
        memo[i] = max(findMaxPoints(values, memo, i - 1), findMaxPoints(values, memo, i - 2) + values[i]);
        
        return memo[i];
    }
};