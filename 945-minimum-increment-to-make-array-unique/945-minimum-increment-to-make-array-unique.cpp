class Solution {
public:
    //https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/2011156/C%2B%2B-or-Most-Intuitive-or-Easiest-Solution-or-Concise-Implementation
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