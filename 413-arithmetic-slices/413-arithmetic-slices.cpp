class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        
        int n=nums.size();
        if(n<3)
            return 0;
        int cnt=0;
        
        for(int i=1;i<n-1;i++)
        {
            int diff=nums[i]-nums[i-1];
            
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]-nums[j-1]==diff)
                    cnt++;
                else break;
            }
        }
        return cnt;
    }
};