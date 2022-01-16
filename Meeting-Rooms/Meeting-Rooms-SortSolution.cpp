//https://www.lintcode.com/problem/920/
//Description
//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//Return True or False

//Input: intervals = [(0,30),(5,10),(15,20)]
//Output: false
//Explanation: (0,30), (5,10) and (0,30),(15,20) will conflict


/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
//Just Check, if EndTime of previous Meeting does not overlap with Starting Time of current Meeting After Sorting by StartTime

//Tc:- (nlogn)

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
     static bool cmp(Interval a, Interval b)
     {
         return a.start<=b.start;
     }
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.empty())return true;

        sort(intervals.begin(),intervals.end(),cmp);

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i-1].end>intervals[i].start)
               return false;
        }
        return true;
    }
};
