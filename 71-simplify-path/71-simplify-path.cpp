class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        
        //to store dir
        stack<string> st;
        
        for(int i=0; i<n; i++){
            string temp;   // to store directory
            
            if(path[i] == '/') continue;
            
            //store dir (a, b, c)
            while(i<n && path[i] != '/')  
                temp += path[i++];
            
            if(temp == ".."){
                if(!st.empty()) st.pop();
            }   
               
            else if(temp == ".") continue;
            
            //push dir 
            else
                st.push(temp);
        }
        
        string ans;
        while(!st.empty()){
            ans = '/' + st.top() + ans;
            st.pop();
        }
        
        if(ans == "") return "/";
        return ans;
    }
};