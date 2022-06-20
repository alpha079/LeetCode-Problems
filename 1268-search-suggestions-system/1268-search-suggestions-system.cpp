//Time Complexity: O(NlogN) + O(MlogN), where N=|products|, M= |searchWord|
//Space: O(1)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& prod, string s) {
        
        
        sort(prod.begin(),prod.end());
        vector<vector<string>> ans;
        int start(0), bStart(0),n=prod.size();
        
        string prefix="";
        for(char c: s)
        {
            vector<string> res;
            prefix+=c;
            start=lower_bound(prod.begin()+bStart,prod.end(),prefix)-prod.begin();
            
            for(int i=start;i<min(start+3,n)&& !prod[i].compare(0,prefix.length(),prefix);i++)
            {
                
                res.push_back(prod[i]);
            }
            ans.push_back(res);
            bStart=start;
        }
        return ans;
    }
};