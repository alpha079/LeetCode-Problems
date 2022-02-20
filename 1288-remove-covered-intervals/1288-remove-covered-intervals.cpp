//https://leetcode.com/problems/remove-covered-intervals/discuss/1784527/C%2B%2B-oror-Easy-To-Understand-oror-Sorting-oror-Short-and-Simple
class Solution {
public:
    
  //TC:- O(NlogN)
  // SC: O(1)
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
            return 1;
        sort(intervals.begin(),intervals.end());
        
        auto current=intervals[0];
        int cnt=1;
        for(int i=1;i<intervals.size();i++)
        {
           if(intervals[i][0]>current[0] and intervals[i][1]>current[1])
           {
               ++cnt;
               
           }
            if(intervals[i][1]>current[1])
               {
                   current=intervals[i];
               }
        }
        return cnt;
        
    }
};