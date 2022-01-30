//https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/discuss/770336/C%2B%2B-0ms-O(n)-using-string-as-stack

//Very Very Important Question

class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> freq(26,0);
        
        vector<bool> vis(26,false);
        
        for(char ch: s)
        {
            freq[ch-'a']++;
        }
        string res="";
        for(int i=0;i<size(s);i++)
        {
            freq[s[i]-'a']--;
            if(vis[s[i]-'a']==true)continue;
            
            //Main loop to lexiographically insert the characters
            while(res.back()>s[i] and freq[res.back()-'a']>0)
            {
                
                vis[res.back()-'a']=false;
                res.pop_back();
            }
            
            
             vis[s[i]-'a']=true;
             res+=s[i];
            
            
        }
        return res;
        
    }
};