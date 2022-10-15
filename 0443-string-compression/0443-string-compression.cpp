class Solution {
public:
    int compress(vector<char>& chars) {
        
        string ans="";
        int cnt=1;
        
        for(int i=0;i<size(chars);i++)
        {
            
            while(i<size(chars)-1 and chars[i+1]==chars[i])
            {
                cnt++;
                i++;
            }
            
            ans+=chars[i];
            
            if(cnt==1)
                continue;
            
            ans+=to_string(cnt);
            cnt=1;
            
            
        }
        chars.clear();
        for(char c: ans)
        {
            chars.push_back(c);
        }
        return chars.size();
    }
};