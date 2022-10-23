class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        
        //TC: O(N) , we perfom traversal two times,but we do not sort the array
        vector<int> res(2,-1);
        int len=nums.size();
      
        for(int i=0;i<len;i++)
        {
            while(nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=i+1)
            {
                return {nums[i],i+1};
            }
        }
        return {};
    }
};

//Assume test case to be [5,1,2,3,5]
// Now if we sort then the time Complxity will bedome O(nlogn)
//So, we have to fix the elments at correct positions
// So we perfom Cyclic Sort