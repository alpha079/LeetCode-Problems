class Solution {
public:
    // Time complexity: O(n * 26) = O(n)
// Time space: O(26 * 2) = O(1)
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        
        vector<int> v1(26),v2(26);
        
        for(char c: s1)
        {
            v1[c-'a']++;
        }
        
       for(int i=0;i<s2.size();i++)
       {
           v2[s2[i]-'a']++;
           
           if(i>=s1.size()-1)
           {
               if(v1==v2)return true; //O(26)
               
               //make char out of window
               v2[s2[i-s1.size()+1]-'a']--;
           }
       }
        return false;
        
    }
};