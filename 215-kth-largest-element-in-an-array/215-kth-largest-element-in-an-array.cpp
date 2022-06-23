class Solution {
public:
    
    void swap(vector<int>& nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
    int findCorrectPivPosition(vector<int>& nums, int low,int r)
    {
        int piv=r;
        r--;
        while(low<=r)
        {
            
            while(low<=r && nums[low]<=nums[piv])
            {
                low++;
            }
            while(low<=r && nums[r]>=nums[piv])
            {
                r--;
            }
            if(r >low)
            {
                //test case:- [3,1,2,4]
                // 2
                swap(nums,low,r);
            }
            
        }
        swap(nums,low,piv);
        return low;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int left=0;
        int right=nums.size()-1;
        k=nums.size()-k;
        while(left<=right)
        {
            int pos=findCorrectPivPosition(nums,left,right);
            if(pos<k)
            {
                left=pos+1;
            }
            else if(pos>k)
            {
                right=pos-1;
            }
            else break;
            
            
        }
        return nums[k];
    }
};