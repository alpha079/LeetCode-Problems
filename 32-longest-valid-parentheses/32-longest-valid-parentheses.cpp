class Solution {
public:
    int longestValidParentheses(string s) {
        
        //Brute force Solution:
        
        if(s.size()==0)
            return 0;
        if(s=="()")
            return 2;
        
        int count=0;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            count=0;
            
            for(int j=i;j<s.size();j++)
            {
                //if not starting bracket then count--;
                if(s[j]=='(')
                    count++;
                else count--;
                
                if(count<0)
                    break;
                
                if(count==0)
                    res=max(res,j-i+1);
            }
        }
        return res;
    }
};