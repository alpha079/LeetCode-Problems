class Solution {
public:
    
    //https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/discuss/1431847/C%2B%2BJavaPython-3-solutions%3A-MinHeap-MaxHeap-QuickSelect-Clean-and-Concise
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
        
        
        //Max heap Implementation
        /*
        
        static public comp(string& a, string& b)
        {
          //if size if equal, then return greater one
          
          if(a.size()==b.size())
          {
          return a<b; if a is smaller than b, return 1, that means do swap
          }
          
          return a.size()<b.size(); //return 1 to do swap;
        }
           priority<string,vector<string>,comp> pq;
           for(auto it: nums)
           {
              pq.push(it);
           }
           k--;
           while(k--)
           {
            pq.pop();
           }
           return pq.top();
        
        */
        
    }
};