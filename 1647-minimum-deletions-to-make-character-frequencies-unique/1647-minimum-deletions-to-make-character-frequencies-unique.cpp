class Solution {
public:
    //TC:- O(NlognN)
    int minDeletions(string s) {
        
     unordered_map<char,int> map;
        
        for(auto it: s)
        {
            map[it]++;
        }
        unordered_set<int> set;
        int ans=0;
        
        for(auto [key,value]: map)
        {
            while(set.find(value)!=set.end())
            {
                value--;
                ans++;
            }
            if(value>0)
                set.insert(value);
        }
        return ans;
        
    }
};