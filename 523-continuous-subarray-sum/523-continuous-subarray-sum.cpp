class Solution {
public:
    //TC:- O(N)
    //SC:- O(K)
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return false;
        }
        
        int sum = nums[0];
        unordered_map<int, int> map;
        map.insert({sum%k, 0});
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            int remainder = sum%k;
            
            if (remainder == 0) { return true; }
            
			// Even if we found a subarray that is a multiple of k, make sure that it is of size 2 or greater.
            
            if (map.find(remainder) != map.end() && i - map[remainder] > 1) {
                return true;
            } else {
                map.insert({remainder, i});
            }
        }
        
        return false;
    }
};