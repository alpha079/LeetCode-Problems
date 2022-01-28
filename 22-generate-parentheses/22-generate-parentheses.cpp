/*
Our complexity analysis based on how many elements there are in generateParenthesis(n).
This is the n-th Catalan number, where the first Catalan numbers for n = 0, 1, 2, 3, ... are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786,...
Time & Space: n-th Catalan Number.
*/

class Solution {
public:
    void helper(int n, vector<string>& res, string ans, int bal)
    {
        if(n==0 && bal==0)
        {
            res.push_back(ans);
        }
        if(n<0 || bal<0)
        {
            return;
        }
        helper(n-1,res,ans+'(',bal+1);
        helper(n-1,res,ans+')',bal-1);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string ans="";
        
        helper(2*n,res,ans,0);
        return res;
        
    }
};