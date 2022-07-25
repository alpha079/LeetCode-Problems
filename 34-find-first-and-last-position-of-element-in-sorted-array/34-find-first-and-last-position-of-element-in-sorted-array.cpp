class Solution {
public:
    //O(logn)+O(logn)
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {FindFastAndLast(nums,target,"FIRST"),FindFastAndLast(nums,target,"LAST")};
        
    }
    int FindFastAndLast(vector<int>& nums, int target,string type)
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
                (type=="FIRST")? high=mid-1:low=mid+1;
               
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