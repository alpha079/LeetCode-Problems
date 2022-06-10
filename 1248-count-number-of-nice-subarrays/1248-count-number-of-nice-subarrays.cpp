//Explanation if the Appraoch
//https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/508217/C%2B%2B%3A-Visual-explanation.-O(1)-space.-Two-pointers

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int low(0);
        int res=0;
        int odd(0);
        int count=0;
        for(int high=0;high<nums.size();high++)
        {
            if(nums[high]& 1) //if current element is odd
            {
                odd++;
                if(odd>=k)
                {
                    count=1;
                    while(!(nums[low++]&1))count++;
                    res+=count;
                }
            }
            else{
                res+=count;
            }
        }
        return res;
    }
};