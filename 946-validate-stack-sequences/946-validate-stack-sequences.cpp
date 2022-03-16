class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int cnt=0;
        for(auto it: pushed)
        {
            st.push(it);
            
            while(!st.empty() and st.top()==popped[cnt])
            {
                st.pop();
                cnt++;
            }
        }
        return st.size()==0;
    }
};