class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k;
        set<string> now;
        for(int i = k; i <= s.length(); i++){
            string a = s.substr(i-k, k);
            // cout << a << endl;
            if(now.find(a) == now.end()){
                now.insert(a);
                need--;
                if(need == 0) return true;
            }
        }
        return false;
    }
};