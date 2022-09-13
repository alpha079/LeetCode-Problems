//https://leetcode.com/problems/product-of-array-except-self/discuss/1597994/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Prefix-and-Suffix-product-O(1)-space-approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> res(n,0);
     /*   for(int i=0;i<n;i++)
        {int value=nums[i];
         int index=i;
         int product=1;
            for(int j=0;j<n;j++)
            {
                if(nums[j]==value and j==i)continue;
                else
                    product*=nums[j];
            }
         res[i]=product;
        }
        [1,2,3,4]
        prefix [1,1,2,6]
        suffix [24,12,4,1]
        */
        vector<int> prefix(n,1);
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        
        for(int i=n-1,suffProd=1;i>=0;i--)
        {
            prefix[i]*=suffProd;
            suffProd*=nums[i];
        }
        return prefix;
        //This appraoch use Only 1 vector
        
    }
};