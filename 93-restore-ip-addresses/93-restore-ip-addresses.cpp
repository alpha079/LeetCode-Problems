class Solution {
public:
    
    bool isValid(string& str)
    {
        if(str.size()>3)
            return false;
        if(str[0]=='0' and str.size()>1)
            return false;
        int value=stoi(str);
        return value>=0 and value<=255;
    }
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        if(s.size()>12)
            return res;
        
        for(int i=1;i<=3 and i<size(s);i++)
        {
            string first=s.substr(0,i);
            if(isValid(first))
            {
                for(int j=1;j<=3 and i+j<size(s);j++)
                {
                    string second=s.substr(i,j);
                    if(isValid(second))
                    {
                        for(int k=1;k<=3 and i+j+k<size(s);k++)
                        {
                            string third=s.substr(i+j,k);
                            string fourth=s.substr(i+j+k);
                            if(isValid(third) && isValid(fourth))
                            {
                                                     res.emplace_back(first+"."+second+"."+third+"."+fourth);
                            }
                        }
                    }
                }
            }
            
        }
        return res;
            
        
    }
};