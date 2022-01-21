/*
Before explaining the algo, we should always keep in mind that every element will be in range of (1,n) where n is the size of input array.

Algorithm:

Scan every element in array.
Negate the value at index of ((absolute value of scanned element) - 1)).
Now check if the value a the index is -ve or not. If positive its a duplicate element .

*/


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]*=-1;
        }
        
        return ans;
    }
};