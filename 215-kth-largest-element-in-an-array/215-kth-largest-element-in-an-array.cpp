class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> heap(nums.begin(),nums.end());
        int res=0;
        while(!heap.empty())
        {
            if(k==1)
            {
                res=heap.top();
            }
            heap.pop();
            k--;
        }
        return res;
        
    }
};