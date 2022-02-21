class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        unordered_map<int,int> map;
        
        for(auto it: nums)
        {
            if(++map[it]>nums.size()/2)
            {
                return it;
            }
        }
        
        return 0;
       
    }
};