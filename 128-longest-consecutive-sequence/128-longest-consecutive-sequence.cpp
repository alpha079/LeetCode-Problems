class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        
        int longest=0;
      for(auto it: s)
      {
          int curr=1;
          for(int j=1;s.count(it-j);j++)
              s.erase(it-j),curr++;
          for(int j=1;s.count(it+j);j++)
              s.erase(it+j),curr++;
          longest=max(longest,curr);
      }
        return longest;
    }
};