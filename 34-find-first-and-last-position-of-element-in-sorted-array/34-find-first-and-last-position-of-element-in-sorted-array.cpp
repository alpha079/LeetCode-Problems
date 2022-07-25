class Solution {
public:
    //O(logn)+O(logn)
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {firstOcc(nums,target),lastOcc(nums,target)};
        
    }
    int firstOcc(vector<int>& nums, int target)
    {
        int res=-1;
        
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target)
            {
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return res;
    }
    int lastOcc(vector<int>& nums, int target)
    {
        int res=-1;
        
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return res;
    }
};