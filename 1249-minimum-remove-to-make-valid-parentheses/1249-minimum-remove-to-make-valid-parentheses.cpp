//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1073189/C%2B%2B-or-2-Approaches-or-O(n)-Beats-100-or-No-Extra-Space-(Best)-or-Explanation

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int open=0;
        
        for(int i=0;i<size(s);i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
                if(open==0)
                    s[i]='#';
                else open--;
            }
        }
        open=0;
         for(int i=size(s)-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                open++;
            }
            else if(s[i]=='(')
            {
                if(open==0)
                    s[i]='#';
                else open--;
            }
        }
        string ans="";
        for(auto c: s)
        {
            if(c!='#')
            {
                ans.push_back(c);
            }
        }
        return ans;
        
    }
};