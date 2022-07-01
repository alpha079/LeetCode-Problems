class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
    for(int i=0;i<size(rocks);i++)
    {
        capacity[i]-=rocks[i];
    }
        sort(begin(capacity),end(capacity));
        int ans=0;
        for(int i=0;i<size(rocks);i++)
        {
            ans+=capacity[i];
            if(ans>additionalRocks)
                return i;
        }
        return size(rocks);
    }
};