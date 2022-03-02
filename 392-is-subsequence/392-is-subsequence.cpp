class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ct = 0;
       
        for (int i = 0; i < t.size(); i++)  if (t[i] == s[ct])  ct++;
        
        return (ct == s.size());
    }
};