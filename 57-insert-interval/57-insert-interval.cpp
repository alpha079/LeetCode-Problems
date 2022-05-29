class Solution {
public:
    //Time: O(Nlogn)
    //SC:- O(res), equal to the merged intervals.
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        
        
       vector<vector<int>> ans;
        
        //1: First skip the intervals that are not within the newIntervals
        //2: Merge the intervals till the newIntervals Range
        //3: Append the larger intervals then the new Intervals
        
        //Given: The List is already sorted
        int high=intervals.size();
        int low=0;
        
        //1: 
        while(low<high && intervals[low][1]<newInterval[0])
        {
            ans.push_back(intervals[low]);
            low++;
        }
        
        //2:
        while(low<high && newInterval[1]>=intervals[low][0])
        {
            newInterval[0]=min(newInterval[0],intervals[low][0]);
            newInterval[1]=max(newInterval[1],intervals[low][1]);
            
            low++;
        }
        ans.push_back(newInterval);
        
        while(low<high)
        {
            ans.push_back(intervals[low]);
            low++;
        }
        return ans;
    }
};