class Solution {
public:
/*    
    //1 3 5 4 2  output is:- 1 4 2 3 5
        5
      3   4
    1       2
//-> First find the point from end , wehre the elements started decreasing (i.e 3, idx1)
// -> Now , find the First smallest greatest element than 3.(i.e idx2)
//Swap elements of both the index.
// now reverse the element of idx1+1 to nums.size();
*/
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size()<2)
            return;
        
        
        int firstDecreasing=-1;
            
            for(int i=nums.size()-2;i>=0;i--)
            {
                if(nums[i]<nums[i+1])
                {
                    firstDecreasing=i;
                    break;
                }
            }
            
            if(firstDecreasing<0)
            {
                //Then i know , input array os the last order of permutation
                //Just revervse the input array, you will get the next permutation
                reverse(nums.begin(),nums.end());
                return;
                
            }

            else{
                int idx=0;
                for(int i=nums.size()-1;i>=0;i--)
                {
                    if(nums[i]>nums[firstDecreasing])
                    {
                        idx=i;
                        break;
                    }
                }
                swap(nums[idx],nums[firstDecreasing]);
            }
           reverse(nums.begin()+firstDecreasing+1,nums.end());
        
    }
    //Tc: O(N)
};