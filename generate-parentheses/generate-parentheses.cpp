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