class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int low=0;
        int res=0;
        int sum=0;
        int right=0;
        while(right<nums.size())
        {
            sum+=nums[right];
            
            while(sum+k<right-low+1)
            {
                res=max(res,right-low);
                sum-=nums[low];
                low++;
            }
            right++;
        }
        return res=max(res,right-low);
        
    }
};