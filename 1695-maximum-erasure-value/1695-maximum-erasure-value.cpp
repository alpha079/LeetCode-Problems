class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_set<int> set;
        
        int low=0;
        int high=0;
        
        int sum=0;
        int maxsum=0;
        while(low<nums.size() && high<nums.size())
        {
            
           
            if(set.find(nums[high])==set.end())
            {   sum+=nums[high];
                maxsum=max(maxsum,sum);
                set.insert(nums[high]);
                high++;
            }
            else{
                sum-=nums[low];
                set.erase(nums[low++]);
                
                
            }
            
        }
        return maxsum;
        
    }
};