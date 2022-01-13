
class Solution {
public:
   
    int findMinArrowShots(vector<vector<int>>& p) {
        
        
        int arrow=0;
        int ans=0;
        sort(p.begin(),p.end());
        int current=p[0][1];
        for(auto it: p)
        {
            if(current>=it[0])
            {
                current=min(current,it[1]);
            }
            else{
                ans++;
                current=it[1];
            }
            cout<<current<<" ";
        }
        ans++;
        return ans;
        
    }
};