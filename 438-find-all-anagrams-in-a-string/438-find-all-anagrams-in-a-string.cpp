class Solution {
public:
    //TC:- O(N)
    //SC:- O(26)
    //Video:- https://www.youtube.com/watch?v=t4sDawyBqYc
    //Using Sliding Window
    vector<int> findAnagrams(string s, string p) {
        int len1=s.size();
        int len2=p.size();
        
        if(len2>len1)
        {
            return {};
        }
        vector<int> ans;
        vector<int>pFreq(26,0);
        vector<int>sFreq(26,0);
        for(int i=0;i<len2;i++)
        {
            pFreq[p[i]-'a']++;
            sFreq[s[i]-'a']++;
        }
        if(pFreq==sFreq)
        {
            ans.push_back(0);
        }
        for(int i=len2;i<len1;i++)
        {
            sFreq[s[i-len2]-'a']--;
            sFreq[s[i]-'a']++;
            
            if(pFreq==sFreq)
            {
                ans.push_back(i-len2+1);
            }
            
        }
        return ans;
    }
};