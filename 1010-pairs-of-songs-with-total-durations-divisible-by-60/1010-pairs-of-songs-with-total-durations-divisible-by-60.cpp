class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n= time.size();
     unordered_map<int,long int> map;
        
        for(auto it: time)
        {
            map[it%60]++;
        }
        
        long int cnt=0;
        
        for(auto it: map)
        {
            if(it.first==0 || it.first==30)
            {
                cnt+=((it.second-1)*(it.second))/2;
            }
            else if(it.first<30 and map.count(60-it.first))
            {
                 cnt+=map[it.first]*map[60-it.first];
            }
        }
        return cnt;
        
    }
};