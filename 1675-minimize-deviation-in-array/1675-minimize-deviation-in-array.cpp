class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> maxh;
        
        int mini=INT_MAX;
        int ans=INT_MAX;
        for(auto it: nums)
        {
            if(it & 1)
            {
                it*=2;
            }
            mini=min(mini,it);
            maxh.push(it);
            
        }
        
        while(!maxh.empty())
        {
            int curr=maxh.top();
            
            maxh.pop();
            ans=min(ans,curr-mini);
            if(curr&1)break;
            
            
            curr/=2;
            
            if(curr<mini)
            {
                mini=curr;
            }
            maxh.push(curr);
        }
        
        return ans;
        
        
    }
};