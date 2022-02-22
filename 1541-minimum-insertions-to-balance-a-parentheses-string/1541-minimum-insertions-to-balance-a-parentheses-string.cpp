class Solution {
public:
 /*
 //https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/780199/JavaC%2B%2BPython-Straight-Forward-One-Pass
 Example 1: Consider ((()(,n= 5 ,i=0,1...4
i=0, we have ( it means we need two right parenthesis (they are in pair) so.. right+=2 => res =0, right =2
i=1, again we have ( it means we need two right parenthesis (they are in pair) so.. right+=2 => res =0, right =4
i=2, again we have ( it means we need two right parenthesis (they are in pair) so.. right+=2 => res =0, right =6
i=3, we have ) we subtract one from right. so.. right-- => res =0, right =5
i=4, we have ( but here right is odd so we need to make it even with right-- and increment res++ => res =1, right =4. Also, as we have got a left parenthesis then we need two right parenthesis (they are in pair) so.. right+=2 => res =1, right =6

finally ans is res + right => 1 +6 == 7

Ex:- ))
 Right=0, right--, -1, right<0, right+=2, right=1, res=1;
 Right--, right=0, right<0 , No
 
 Right+ res= 0+1
    
*/
    int minInsertions(string s) {
        
        int right=0,res=0;
        
        for(auto c: s)
        {
            if(c=='(')
            {
                if(right%2!=0)
                {
                    right--;
                    res++;
                }
                right+=2;
                    
            }
            else{
                right--;
                if(right<0)
                {
                    right+=2;
                    res++;
                }
            }
        }
        return res+ right;
        
    }
};