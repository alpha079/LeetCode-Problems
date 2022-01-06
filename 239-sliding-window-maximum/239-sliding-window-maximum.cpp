//Solution using Priority Queue
// Time: O(NlogN), each operation of maxHeap of size N costs O(logN)
//Space: O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            if(i+1>=k)
            {
                res.push_back(pq.top().first);
                
            }
            while(!pq.empty() and i-pq.top().second+1>=k)
            {
                pq.pop();
            }
        }
        return res;
        
    }
};