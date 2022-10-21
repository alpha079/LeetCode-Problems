class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        unordered_map<int,int> map;
        
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(map[nums[i]]==0)
            {
                map[nums[i]]=i+1;
                
                    
                    
                    
                    
                    
                    
            }
            else 
            {
                if((i-map[nums[i]]+1)<=k)
                    return true;
                else map[nums[i]]=i+1;
            }
                
            
        }
                return false;
    }
};