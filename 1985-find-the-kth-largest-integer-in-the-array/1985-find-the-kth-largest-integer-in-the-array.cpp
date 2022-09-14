class Solution {
public:
    //TC:- O(Nlogn)
    
     static bool compare(string& a, string& b)
    {
        if(a.size()==b.size())
            return a>b;
        else return a.size()>b.size();
    }
    struct comparator
    {
        bool operator () (string& a, string& b)
        {
            if(a.size() == b.size())
                return a > b;
            else
                return a.size() > b.size();
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        
        //sort(nums.begin(),nums.end(),compare);
        
        priority_queue<string,vector<string>,comparator> pq;//Min-Heap declaration
        //TC:- O(nlogk)
        
        /*Time: O(NlogK * M), where N <= 10^4 is length of nums array, K <= N is the kth largest element need to output, M <= 100 is length of each num.
Explain: The MinHeap keeps up to K elements, each heappush/heappop operator costs O(logK). We iterate all elements in nums and push/pop to the MinHeap N times. We need to multiply by M as well, since in the worst case, we need to compare strings by their lexicographically.
Space: O(K)
    */
        for(auto it: nums)
        {
            pq.push(it);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        return pq.top();
        
    }
};