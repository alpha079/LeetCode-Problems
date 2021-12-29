class Solution {
public:
    
    //Test Cases other than the Given Inputs
    // 1: ab2[cd]ef   2: ab2[cd]ef3[gh]ij 
    
    //How Will you handle if there is a exisitng String befoe getting first number
    
    string repeat(int times, string s)
    {
        string res="";
        for(int i=0;i<times;i++)
        {
            res+=s.substr(0,size(s));
        }
        return res;
    }
    string decodeString(string s) {
        stack<pair<string,string>> st;
        
        string ans="";
        string num="";
        string res="";        
        for(auto c: s)
        {
            if(isalpha(c))
                ans+=c;
            else if(isdigit(c))
                num+=c;
            else if(c=='[')
                st.push({move(ans),move(num)});
            else{
                auto [prev,cnt]=st.top();st.pop();
                ans=prev+ repeat(stoi(cnt),ans);
                
            }
        }
        return ans;
        
        
        
    }
};