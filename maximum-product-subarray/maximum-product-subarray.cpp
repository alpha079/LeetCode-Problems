class Solution {
public:
    
    //Solution Explained in  https://leetcode.com/problems/maximum-product-subarray/discuss/1608800/C%2B%2B-or-Discussion-in-detail-or-Easy-to-understand
    
    /*Brute Force Solution O(n^2)
        int prod=INT_MIN;
        
        for(int i=0;i<size(nums);i++)
        {
            int curr=1;
            for(int j=i;j<size(nums);j++)
            {
                curr*=nums[j];
                prod=max(prod,curr);
            }
            
        }
        return prod;
         */
    int maxProduct(vector<int>& nums) {
        
        //Taking the product from left to Right
        
        int prod=1, res=INT_MIN;
        for(auto it: nums)
        {
            prod=prod*it;
            res=max(prod,res);
            if(prod==0)
            {
                prod=1;
            }
            
        }
        prod=1;
        for(int i=size(nums)-1;i>=0;i--)
        {
            prod=prod*nums[i];
            res=max(prod,res);
            if(prod==0)
            {
                prod=1;
            }
            
        }
        return res;
        
       
    }
};