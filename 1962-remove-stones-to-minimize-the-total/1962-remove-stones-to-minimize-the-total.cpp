class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> maxh;
        
        for(auto it: piles)
        {
            maxh.push(it);
        }
        
        while(k>0 and maxh.empty()==false)
        {
            int curr=maxh.top();
            maxh.pop();
            
            curr++;
            curr/=2;
            maxh.push(curr);
            k--;
        }
        int ans=0;
        while(maxh.empty()==false)
        {
            ans+=maxh.top();
            maxh.pop();
        }
        return ans;
        
    }
};