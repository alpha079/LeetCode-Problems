bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1]<b[1];
}
class Solution {
public:
    
    //TC:- O(nlogn)
    int findMinArrowShots(vector<vector<int>>& p ) {
        
        int ans=0;
        
        int arrow=0;
        sort(p.begin(),p.end(),cmp); //Sorted by EndPoint
        
        for(auto it: p)
        {
            if(ans==0 || it[0]>arrow)
            {
                ans++;
                arrow=it[1];
            }
        }
        return ans;
        
    }
};