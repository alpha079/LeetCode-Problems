class Solution {
public:
    string ConvertToString(vector<string> &sol) {
    return sol[0] + '.' + sol[1] + '.' + sol[2] + '.' + sol[3];
  }
    void MakeIP(string& s, vector<string>& res,vector<string>& ans,int begin )
    {
        
        if(ans.size()==4)
        {
            if(begin==s.length())
            {
                res.push_back(ConvertToString(ans));
            }
            return;
        }
        for(int i=1;i<=3 and begin+i<=size(s);i++)
        {
            string temp=s.substr(begin,i);
            if((temp[0]=='0' and temp.size()>1)||  stoi(temp)>255)
                return;
            ans.push_back(temp);
            MakeIP(s,res,ans,begin+i);
            ans.pop_back();
        }
        
        
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res,ans;
        
        if(s.size()<4 || s.size()>12)
            return res;
        
        MakeIP(s,res,ans,0);
        return res;
        
    }
};