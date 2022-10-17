class Solution {
public:
    bool checkIfPangram(string s) {
        
        
        vector<int> fre(26,0);
        
        for(auto c: s)
        {
            fre[c-'a']++;
        }
        
        for(auto it: fre)
        {
            if(it==0)
                return false;
        }
        return true;
        
    }
};