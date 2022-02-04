class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int cnt=0;
        deque<int> dq;
        int ans=0;
        
        for(int right=0;right<nums.size();right++)
        {
            if(nums[right]==0)
                dq.push_back(right);
            while(dq.size()>k)
            {
                left=dq.front()+1;
                dq.pop_front();
            }
            ans=max(ans,right-left+1);
        }
        return ans;
        
    }
};