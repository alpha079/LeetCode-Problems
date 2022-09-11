class Solution {
public:
    
    //TC:- O(N* (logk + logn))
    //SC:- O(N+K)
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
       int MOD = 1e9 + 7;
        
        vector<pair<int,int>> v(n);
        
        for(int i=0;i<speed.size();i++)
        {
            v[i]={efficiency[i],speed[i]};  //(N)
        }
        
        sort(v.rbegin(),v.rend()); //sorted in decreasing order  O(Nlogn)
        
        priority_queue<int,vector<int>,greater<int>> minheap;
        
        long sum=0;
        long result=0;
        for(auto& [e,s]:v)  //O(nlogk)
        {
            minheap.push(s);
            sum+=s;
            
            if(minheap.size()>k)
            {
                sum-=minheap.top();
                minheap.pop();
            }
            
            result=max(result,sum*e);
        }
        return result%MOD;
        
        
        
        
        
       
        
        
    }
};