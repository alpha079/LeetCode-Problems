class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum < x) return -1;
        if(sum==x)return nums.size();
        int target=sum-x;
        int low=0;
        
        int ans=0;
        int current=0;
        for(int high=0;high<nums.size();high++)
        {
            current+=nums[high];
            
            while(current>target)
            {
                current-=nums[low++];
            }
            if(current==target)
            {
                ans=max(ans,high-low+1);
            }
         
        }
        return ans==0 ?-1:nums.size()-ans;
    }
};