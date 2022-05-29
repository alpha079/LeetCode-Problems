class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        
        int res=0;
        
        vector<vector<int>> ans;
        //auto it= intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=intervals[res][1])
            {
                intervals[res][0]=min(intervals[i][0],intervals[res][0]);
                intervals[res][1]=max(intervals[i][1],intervals[res][1]);
            }
            else
            {
                res++;
                intervals[res]=intervals[i];
            }
            
        }
        for(int i=0;i<=res;i++)
        {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};