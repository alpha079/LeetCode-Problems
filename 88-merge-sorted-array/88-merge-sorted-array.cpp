class Solution {
public:
    void merge(vector<int>& nums, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,cnt=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums[i]>nums2[j])
            {
                nums[cnt--]=nums[i--];
            }
            else
                nums[cnt--]=nums2[j--];
        }
        while(j>=0)
            nums[cnt--]=nums2[j--];
    }
};
