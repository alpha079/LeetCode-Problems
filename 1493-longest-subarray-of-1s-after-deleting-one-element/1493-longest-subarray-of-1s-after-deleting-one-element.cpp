class Solution {
public:
    int helper(vector<int>& nums, int skip)
{
	int cnt=0;
	int len=0;
	for(int i=0;i<nums.size();i++)
	{
		if(i==skip)continue;
		if(nums[i]==1)
		{
			cnt++;
			len=max(len,cnt);

		}
		else cnt=0;
	}
	return len;
}
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==0)return 0;

	int zeroes=0;
        int ans=0;

	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==0)
		{
			//start counting the number of 1's excluding the current 0;
			ans=max(ans,helper(nums,i));
			zeroes++;
		}
	}
	if(zeroes==0)
		return nums.size()-1;
	return ans;
    }
};