class Solution {
public:
//TC:- O(N)
//Sc:- O(N)
    string minRemoveToMakeValid(string s) {
        
     stack<int> st;
        
        for(int i=0;i<size(s);i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty())
                {
                    s[i]='#';
                }
                else{
                    st.pop();
                }
            }
        }
        
        //Now if stack is not empty, pop the elements ony by one and put '#' there
        
        while(!st.empty())
        {
            s[st.top()]='#';
            st.pop();
        }
        
        //now again iterate the string and pop the '#' form from the string

        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='#'){ // append not marked character to the end of "ans"
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};