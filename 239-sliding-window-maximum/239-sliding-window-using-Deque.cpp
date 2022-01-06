//Now using Deuque (Double ended queue)
// Since all the elements will be pushed into/ popped out of the buffer only once, so the time complexity is O(N).
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for(int i=0;i<nums.size();i++)
        {
            //Now, if curr element is grater than the Back of the deque,
            //Push it into the deque
            while(!dq.empty() and nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(i+1>=k) //push into the res, if we got the window complete
            {
                res.push_back(nums[dq.front()]);
            }
            
            //pop-out the elements from the front, if the element is not in the window
            if(dq.front()<=i-k+1)
                dq.pop_front();
        }
        return res;
        
    }
};
