//Solution using Priority Queue
// Time: O(NlogN), each operation of maxHeap of size N costs O(logN)
//Space: O(N)
//Input: arr[] = {10, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
//Output: 10 3 4 5 5 5 6

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> pq;
        vector<int> res;
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