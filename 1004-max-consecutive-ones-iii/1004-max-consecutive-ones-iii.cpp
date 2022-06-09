class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        //Using Deque
        deque<int> dq;
        int low=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                dq.push_back(i);
            while(dq.size()>k)
            {
                low=dq.front()+1;
                dq.pop_front();
            }
            res=max(res,i-low+1);
        }
        return res;
    }
};