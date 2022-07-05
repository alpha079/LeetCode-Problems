/*
We can form a solution without the need to spend time erasing elements from the hashset.

Instead of taking the first element that we find in the hashset and iterating both forward and backward, we can just keep skipping till we find that hashset contains num - 1. Finally, we can just iterate in the forward direction till we find consecutive elements in hashset and update longest at the end
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        
        int longest=0;
      for(auto it: s)
      {
          if(s.count(it-1))continue;
          int j=1;
          while(s.count(it+j))
          {
              j++;
          }
          longest=max(longest,j);
          
      }
        return longest;
    }
};