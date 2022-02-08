class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        if(str.size()==0)
            return "";
        
        string res="";
        
        sort(str.begin(),str.end());
        
        auto start=str.front();
        auto back=str.back();
        
        for(int i=0;i<size(start);i++)
        {
            if(start[i]==back[i])
            {
                res+=start[i];
            }
            else break;
        }
        return res;
        
        
        
    }
};