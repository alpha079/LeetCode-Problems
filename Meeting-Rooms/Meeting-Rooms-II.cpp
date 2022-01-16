//Return the minimum number of rooms for all the meeting to be held.

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)

*/

//Here we have two Solution , Based on the type of Input Given


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

class Solution {
public:
	//Tc:- O(nlogn)
	//Sc:- O(n)
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
     static bool cmp(Interval a, Interval b)
     {
         if(a.start!=b.start)
           return a.start<b.start;
        else
           return a.end<b.end;
     }
    int minMeetingRooms(vector<Interval> &intervals) {

        if(intervals.empty())
           return 0;
        //sort(intervals.begin(),intervals.end(),cmp);
        map<int,int> m;

        for(auto it: intervals)
        {
            m[it.start]++;
            m[it.end]--;
        }
        int res=0;
         int temp=0;
        for(auto it:m)
        {
            temp+=it.second;
            res=max(res,temp);

        }
        return res;
        
    }
};

//If in this question, I have benn given with  2D array, then 
//I will push the starting time into one vector
//will push the ending time into another vector
//Then sort both the vectors
// Then Run the below logic

int minMeetingRooms(vector<vector<int>> input) {

        if(input.empty())
           return 0;

       vector<int> start;
       vector<int> end;
       for(auto it: input)
       {
       	start.push_back(it[0]);
       	end.push_back(it[1]);
       }
       sort(start.begin().start.end());
       sort(end.begin(),end.end());

       int i=0,j=0;
       int rooms=0;

       while(i<start.size())
       {
       	if(start[i]<end[j])
       	{
       		i++;rooms++;
       	}
       	else{
       		j++;i++;
       	}
       }
        return rooms;

        //two pointer Appraoch
        //TC: O(nlogn)
        //SC:- O(2*n)
        
    }

