//https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.begin()+k); //(klogk)
        
        for(int i=k;i<nums.size();i++) //O(n)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
    
    //O(n +klogk)
};