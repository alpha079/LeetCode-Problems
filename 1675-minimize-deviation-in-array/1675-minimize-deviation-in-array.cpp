class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        set<int> s;
        
        for(auto it: nums)
        {
             if(it&1)
             {
                 s.insert(it*2);
             }
            else s.insert(it);
        }
        
        int ans=INT_MAX;
        
        while(*s.rbegin()%2==0)
        {
            int currMax=*s.rbegin();
            s.erase(*s.rbegin());
            s.insert(currMax/2);
            ans=min(ans,*s.rbegin()-*s.begin());
        }
        return ans;
    }
};