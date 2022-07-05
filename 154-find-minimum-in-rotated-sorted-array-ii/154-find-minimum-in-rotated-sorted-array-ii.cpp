class Solution {
public:
    int findMin(vector<int>& nums) {
        //[5,5,5,5,5,5,5,5,1,5,5]
        
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]<nums[n-1])return nums[0];
        int left=0,right=n-1;
        int mid=0;
        
        while(left<right)
        {
            mid=(left+right)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else if(nums[mid]<nums[right])
                right=mid;
            else right--; //This is for case 5,5,5,5,5,1,5,5
        }
        return nums[left];
    }
};