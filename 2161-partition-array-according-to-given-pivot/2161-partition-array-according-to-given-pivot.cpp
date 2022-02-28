class Solution {
public:
    //Using Three Traversals
    //O(N) Solution
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> res;
        
        for(auto it: nums)
        {
            if(it<pivot)
            {
                res.push_back(it);
            }
           
        }
        
        for(auto it: nums)
        {
            if(it==pivot)
            {
                res.push_back(it);
            }
        }
        for(auto it: nums)
        {
            if(it>pivot)
            {
                res.push_back(it);
            }
        }
        return res;
        
    }
};