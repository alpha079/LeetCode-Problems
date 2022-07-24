//This is also the code
//https://leetcode.com/problems/number-of-zero-filled-subarrays/discuss/2322517/mathcppeasywith-explanationtime-on-space-o1
class Solution {
public:
    
/*
 Make the logic
 number of zero |   Number of subarrays
 1                   1
 2                   2 + 1=3
 3                   3+ 2+ 1= 6
 4                   4 + 3+ 2 + 1=10
 
 Now, there can chances that we might get a number greater than zero between consecutive zeroes's
 like 1,3,0,0,2,0,0,4. So we have to reset the count of zero

*/
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans=0;
        long long cnt=0;
        
        for(auto it: nums)
        {
            if(it==0)
            {
                cnt++;
                ans+=cnt;
            }
            else cnt=0;
        }
        return ans;
        
    }
};