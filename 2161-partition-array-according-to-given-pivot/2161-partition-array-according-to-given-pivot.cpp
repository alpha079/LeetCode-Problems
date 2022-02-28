class Solution {
public:
  //LInk:-
    //https://leetcode.com/problems/partition-array-according-to-given-pivot/discuss/1747115/Solution-for-C%2B%2B-three-pointers-O(N)
    //Three Pointers and two loops
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int low=0;
        int same=0;
        int high=nums.size();
        
        for(auto it: nums)
        {
            if(it<pivot)
            {
                ++same;
            }
            else if(it>pivot)
            {
                --high;
            }
        }
        vector<int> res(nums.size());
        for(auto it: nums)
        {
            if(it==pivot)
            {
                res[same++]=it;
            }
            else if(it<pivot)
            {
                res[low++]=it;
            }
            else res[high++]=it;
        }
        return res;
    }
};