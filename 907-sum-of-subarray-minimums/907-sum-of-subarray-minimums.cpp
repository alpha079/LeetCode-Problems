class Solution {
public:
    //Explained in this video https://www.youtube.com/watch?v=9-TXIVEXX2w
    //Leetcode discuss:-
    //https://leetcode.com/problems/sum-of-subarray-minimums/discuss/1405264/C%2B%2B-oror-Monotonic-Stack-oror-Detailed-Explanation
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            
            while(!s.empty() and arr[i]<arr[s.top()])
            {
                s.pop();
            }
            if(!s.empty())
            {
                left[i]=i-s.top();
            }
            else left[i]=i+1;
            
            s.push(i);
        }
        while(!s.empty())
        {
            s.pop();
        }
         for(int i=n-1;i>=0;i--)
        {
            
            while(!s.empty() and arr[i]<=arr[s.top()])
            {
                s.pop();
            }
            if(!s.empty())
            {
                right[i]=s.top()-i;
            }
            else right[i]=n-i;
            
            s.push(i);
        }
        
        int mod=(int)1e9+7;
        int res=0;
        for(int i=0;i<n;i++)
        {
            long long prod=(left[i]*right[i])%mod;
            prod=(prod*arr[i])%mod;
            res=(res+prod)%mod;
            
        }
        return res%mod;
        
     //   **Time : O(N + N + N) = O(3N) ~ O(N)
//Space : O(3N) ~ O(N)

        
    }
};