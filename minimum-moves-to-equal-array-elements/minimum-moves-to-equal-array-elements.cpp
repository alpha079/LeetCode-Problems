//See this problem to decrease the value of every element by making every element equal to the smallest.

/*Approach:

The question says we need to increment all the elements of the array by one, except any one, to finally make all the array elements as equal.
Reversely, we can think of actually decreasing any one of the elements until all the elements become equal (infact, equal to the minimum element value of the array.)
Let me provide an example to clarify point number 2:
suppose-

original array: [1, 2, 3]
Following step 2, we get-
[1, 2, 3] -> [1, 2, 2] -> [1,1 2] -> [1, 1, 1].
Hence, a total of 3 moves (which is same as that of incrementing n-1 values by 1).

Now, if we observe here, we are actually decresing any number y to x, where x is the minimum element value of the array given.

Therefore, in the above example, output is = (3-1) + (3-2) = 3, [where 1 is the minimum element value in array].

*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int small=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            small=min(small,nums[i]);
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==small)
                continue;
            else ans+=nums[i]-small;
        }
        return ans;
    }
};
//Time:- O(n)