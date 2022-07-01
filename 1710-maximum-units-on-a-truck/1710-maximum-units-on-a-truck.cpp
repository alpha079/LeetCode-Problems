class Solution {
public:
    //TC:- O(N) Counting Sort
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        
       vector<int> freq(1001,0);
        for(auto it: boxes)
        {
            freq[it[1]]+=it[0];
        }
        int res=0;
        
        for(int i=1000;i>=0 and truckSize>0;i--)
        {
            res+=min(truckSize,freq[i])*i;
            truckSize-=freq[i];
        }
        return res;
    }
};