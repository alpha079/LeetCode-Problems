class Solution {
public:
    
    struct comp{
        
        bool operator()(const pair<int,string>& a,const pair<int,string>& b)
        {
        //if freq are equal , then sort lexicographically
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        
        return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> map;
        
        for(auto it: words)
        {
            map[it]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>,comp> pq;
        
        
        for(auto it: map)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<string> res;
       while(pq.size())
       {
           res.push_back(pq.top().second);
           pq.pop();
       }
        reverse(res.begin(),res.end());
        return res;
    }
};