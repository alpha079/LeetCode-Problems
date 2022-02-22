class Solution {
public:
    int minInsertions(string s) {
        
        stack<int> st;
        int ans=0;
        for(int i=0;i<size(s);i++)
        {
            if(s[i]=='(')
            {
                //if tsakc is empty or top os stack is 2, just again push 2;
                if(st.empty() || st.top()==2)
                {
                    st.push(2);
                }
                else{
                // if there is 1,that means one '(', pop that out, increase the count of ans, then again push 2
                    st.pop();
                    st.push(2);
                    ans++;
                    
                }
            }
            else{
                
            // Case :- if stack is empty, and we encountered ')', then push 1, and increment ans
                if(st.empty())
                {
                    st.push(1);ans++;
                }
            //case 2: if st.top is '1', just pop the element, st.pop(), we already increased the count in above 'if case'
                else if(st.top()==1)
                {
                    st.pop();
                }
                //here st.top is '(', then pop first, then push 1.
                else if(st.top()==2){
                    st.pop();
                    st.push(1);
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};