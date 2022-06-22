class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        
        int cnt=1;
        int longest=0;
       for(auto it: s)
       {
           if(s.count(it-1))continue;
           
           int j=1;
           while(s.count(it+j))j++;
           longest=max(longest,j);
       }
        return longest;
    }
};