class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        //TC:- O(N^2)
        // We can optimise it by declaring a visiting array, that the Employee has
        // been already informed
        int ans=0;
        
        for(int i=0;i<manager.size();i++)
        {
            int j=i;
            int time=0;
            while(j!=headID)
            {
                time+=informTime[manager[j]];
                j=manager[j];
            }
            ans=max(time,ans);
        }
        return ans;
    }
};