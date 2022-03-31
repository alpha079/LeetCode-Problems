class Solution {
    public int splitArray(int[] nums, int m) {
        /**
            Binary Search range:[l = max(nums), r = sum(nums.length - 1)]   
            candidate m, computer number groups needed x where sum(subRange) <= c
            if x > m
                l = c + 1
            else 
                r = c
        */
        int sums = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sums += nums[i];
            max = Math.max(max, nums[i]);
        }
        int l = max;
        int r = sums;
        while (l < r) {
            int c = l + (r - l) / 2;
            int x = getSubRangesCount(nums, c);
            if(x > m) {
                l = c + 1;
            } else {
                r = c;
            }
        }
        return l;
    }
    public int getSubRangesCount(int[] nums, int c) {
        int count = 0;
        int j = -1;
        int sum = 0;
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if(sum > c) {
                count++;
                sum = nums[i];
            }
        }
        return count + 1;
    }
}