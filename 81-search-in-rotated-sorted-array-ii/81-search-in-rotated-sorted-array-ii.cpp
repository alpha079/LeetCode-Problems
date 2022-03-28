class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n=nums.size();
        if(n==0)return false;
        if(n==1)
        {
            return (nums[0]==target?true:false);
        }
        
        int low=0,high=n-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            
            if(nums[low]==nums[mid]&& nums[mid]==nums[high])
            {
                while(low<=high && nums[low]==nums[mid]&& nums[mid]==nums[high] )
                {
                    low++;
                    high--;
                }
            }
            //Checking if mid lies in left part or right
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] && target<nums[mid])
                {
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>nums[mid]&& target<=nums[high])
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};