class Solution {
public:
    //TC:- O(NlognN)
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        
       sort(begin(boxes), end(boxes), [](auto &a, auto &b){return a[1] > b[1];});
        
        int ans=0;
        
        for(auto it: boxes)
        {
            if(truckSize<=0)break;
            ans+=min(truckSize,it[0])*it[1];
            truckSize-=it[0];
        }
        return ans;
        
    }
    static bool cmp(vector<vector<int>>& a, vector<vector<int>>& b)
    {
        return a[1]>b[1];
    }
};