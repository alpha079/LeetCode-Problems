class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> map;
        
        for(auto it: arr)
        {
            map[it]++;
            
        }
        
        
        set<int> s;
        for(auto it: map)
        {
            if(s.find(it.second)!=s.end())
                return false;
            s.insert(it.second);
        }
        return true;
    }
};