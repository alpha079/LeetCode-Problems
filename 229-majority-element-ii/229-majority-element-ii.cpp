class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> map;
        
        for(auto it: nums)
        {
            map[it]++;
        }
        vector<int> res;
        
        for(auto it: map)
        {
            if(it.second>nums.size()/3)
            {
                res.push_back(it.first);
            }
        }
        
        return res;
    }
};