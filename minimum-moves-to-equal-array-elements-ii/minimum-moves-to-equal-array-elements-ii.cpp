//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/1217485/Min-Moves-to-Make-Array-Elements-Equal-2-or-C%2B%2BPythonJava-2-Solutions-Explained

/*
-------Method 1:-------
If you observe, once all the numbers are sorted, the minimum moves required to make all array elements equal is by moving up, i.e. increasing the numbers from the left end and moving down, i.e. decreasing the numbers from the right end until all the numbers become equal. You will notice that all the numbers become equal mid-way. Hence, the intuition is that you must make all numbers equal to the middle number in the sorted array for the minimum number of moves. Hence, the absolute difference of the current number and the middle number is the number of moves required for this number. The sum of absolute difference for all the numbers is your answer.

Lets' take this for example: [1, 2, 3, 4, 5]
Middle number = 3

Move 1: [2, 2, 3, 4, 5], count = 1
Move 2: [3, 2, 3, 4, 5], count = 2
Move 3: [3, 3, 3, 4, 5], count = 3
Move 4: [3, 3, 3, 3, 5], count = 4
Move 5: [3, 3, 3, 3, 4], count = 5
Move 6: [3, 3, 3, 3, 3], count = 6 ---> answer

This is same as the absolute difference logic explained above:

For the array: [1, 2, 3, 4, 5]:

Step 1: abs (1 - 3) = 2, count = 0+2 = 2
Step 2: abs (2 - 3) = 1, count = 2+1 = 3
Step 3: abs (3 - 3) = 0, count = 3+0 = 3
Step 4: abs (4 - 3) = 1, count = 3+1 = 4
Step 5: abs (5 - 3) = 2, count = 4+2 = 6 ---> answer

*/
//Tc:O(nlogn)
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums.size()/2;
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            cnt+=abs(nums[i]-nums[mid]);
        }
        return cnt;
        
    }
};
//
