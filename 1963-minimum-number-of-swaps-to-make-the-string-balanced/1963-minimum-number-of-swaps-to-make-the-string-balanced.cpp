class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int swap=0;
       for(int i=0;i<size(s);i++)
       {
           if(s[i]=='[')
           {
               st.push(s[i]);
           }
           else{
               if(!st.empty())
               {
                   st.pop();
               }
               else swap++;
           }
           
       }
        return (swap+1)/2;
    }
};