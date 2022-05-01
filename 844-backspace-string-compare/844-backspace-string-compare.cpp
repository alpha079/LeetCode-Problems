class Solution {
public:
    string build(string s) {
        string noHashS;
        for(char c : s) {
            if(c == '#') {
                if(noHashS.length()) {
                    noHashS.pop_back();
                }
            } else {
                noHashS += c;
            }
        }
        return noHashS;
    }
    
    bool backspaceCompare(string s, string t) {
        return(build(s) == build(t));
    }
};