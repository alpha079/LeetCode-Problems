class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first=-1;
        int last=-1;
        
        int i=0;
        for(auto it: nums)
        {
            if(it==target)
            {
                first=i;
                break;
            }
            i++;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(nums[j]==target)
            {
                last=j;
                
            }
        }
        
        return {first,last};
        
    }
};