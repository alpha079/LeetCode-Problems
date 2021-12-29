class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if( nums.size()==0)
            return 0;
        
        int maxp=nums[0];
        int minp=nums[0];
        
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(minp,maxp);
            
            maxp=max(nums[i],maxp*nums[i]);
            minp=min(nums[i],minp*nums[i]);
            
            if(maxp>ans)
            {
                ans=maxp;
            }
            
        }
        return ans;
        
    }
};
