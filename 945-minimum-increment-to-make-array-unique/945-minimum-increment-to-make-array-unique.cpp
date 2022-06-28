// Code 1 : More optmised approaches in later submissions

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int> set;
        int ans=0;
        
        for(auto it: nums)
        {
            if(set.find(it)==set.end())
            {
                set.insert(it);
            }
            else{
                int ptr=*(set.rbegin());
                ptr++;
                ans+=ptr-it;
                set.insert(ptr);
            }
        }
        return ans;
        
    }
};