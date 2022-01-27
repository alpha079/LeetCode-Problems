class Solution {
public:
    
    // Time: O(N)
// Space: O(N)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        
        unordered_map<int,int> map;
        
        stack<int> s;
        
        for(auto it: nums2)
        {
            while(!s.empty() and it>s.top())
            {
                map[s.top()]=it;
                s.pop();
            }
            s.push(it);
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(map.find(nums1[i])!=map.end())
            {
                res[i]=map[nums1[i]];
            }
        }
        return res;
    }
};