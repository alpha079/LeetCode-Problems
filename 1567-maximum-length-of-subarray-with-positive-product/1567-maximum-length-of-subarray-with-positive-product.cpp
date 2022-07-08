//https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/824426/Fully-Explained-Solution-oror-Using-simple-concept-of-odd-and-even-oror-O(n)-Solution
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
    
        int n=nums.size();
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            int neg=0,pos=0,negS=-1,negE=-1,j;
            
            for( j=i;j<n;j++)
            {
                if(nums[j]<0)neg++;
                if(nums[j]>0)pos++;
                if(nums[j]<0 && negS==-1)negS=j;
                if(nums[j]<0)negE=j;
                if(nums[j]==0)break;
            }    
                if(neg%2==0)
                   maxLen=max(maxLen,neg+pos);
                   
                if(neg%2==1){
                    maxLen=max(maxLen,j-negS-1);
                    maxLen=max(maxLen,negE-i);
                }   
            
             i=j;
        }
                   return maxLen;
    }
};