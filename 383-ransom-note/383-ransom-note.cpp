class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<char> hh;
        for(char x:magazine)
            hh.push_back(x);
        
        for(char x:ransomNote)
        {
            auto it=find(hh.begin(),hh.end(),x);
            if(it==hh.end())
                return false;
            *it=' ';
        }
        return true;
    }
};