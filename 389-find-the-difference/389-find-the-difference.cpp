class Solution {
public:
    char findTheDifference(string s, string t) {
        
        
        unordered_map<char,int> map;
        
        for(char c: t)
        {
            map[c]++;
        }
        for(char c: s)
        {
            map[c]--;
        }
        char res;
        for(auto it: map)
        {
            if(it.second==1)
                res= it.first;
        }
        return res;
        
    }
};