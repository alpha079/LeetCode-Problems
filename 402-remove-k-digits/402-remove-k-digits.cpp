class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n=num.size();
        if(k==n)return "0";
        
        string res="";
        
        for(int i=0;i<num.size();i++)
        {
            
            while(!res.empty() && res.back()>num[i] and k>0)
            {
                res.pop_back();
                k--;
            }
            if(!res.empty() || num[i]!='0')
            {
                res+=num[i];
            }
        }
        //Now If case is "12345" k=3
        while(k-- && !res.empty())
        {
            res.pop_back();
        }
        return res.size()>0 ? res: "0";
        
        
    }
};