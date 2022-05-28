class Solution {
public:
    int missingNumber(vector<int>& nums) {
       //First appraoch
        //int n=nums.size();
        //return n*(n+1)*0.5 - accumulate(nums.begin(),nums.end(),0);
        
        
        //Second Appraoch Using XOR
        //1 2 0 4 , missing is 3 
        int ans=nums.size(); //4
        
        for(int i=0;i<nums.size();i++)
        {
            ans^=i^nums[i];
        }
        return ans;
        
    }
};