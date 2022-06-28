class Solution {
public:
    const int N = 2e5 + 5;
    int minIncrementForUnique(vector<int>& nums) {
        
        vector<int> freq(N,0);
        
        for(auto it: nums)
        {
            freq[it]++;
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            if(freq[i]<=1)continue;
            
            freq[i+1]+=freq[i]-1;
            ans+=freq[i]-1;
        }
        return ans;
    }
};