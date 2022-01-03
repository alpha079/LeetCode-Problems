//Trapping Rainwater O(1) Space 
//https://leetcode.com/problems/trapping-rain-water/discuss/1374608/C%2B%2BJavaPython-MaxLeft-MaxRight-so-far-with-Picture-O(1)-space-Clean-and-Concise

class Solution { // 0 ms, faster than 100.00%
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int n = height.size(), maxLeft = height[0], maxRight = height[n-1];
        int left = 1, right = n - 2, ans = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ans += maxLeft - height[left];
                left += 1;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ans += maxRight - height[right];
                right -= 1;
            }
        }
        return ans;
    }
};

