class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.length()==0 || t.length()==0 || s.length()<t.length())
            return "";
        
       unordered_map<char,int> map;
        for(auto it: t)
        {
             map[it]++;
        }
        int count=0;
        int low=0,high=0;
        int ans_start=0;
        int minlength=INT_MAX;
        while(high<s.size())
        {
            
            if(map[s[high]]>0)
                count++;
            map[s[high]]--;
           
                while(count==(int)t.size())
                {
                    if(minlength>high-low+1)
                    {
                        minlength=high-low+1;
                        ans_start=low;
                    }
                    map[s[low]]++;
                    if(map[s[low]]>0)
                        count--;
                    low++;
                }
            
            high++;
        }
        return minlength==INT_MAX ? "":s.substr(ans_start,minlength);
    }
};