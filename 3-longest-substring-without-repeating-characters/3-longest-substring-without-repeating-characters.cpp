class Solution {
public:
    //Find operation in unordered_set is O(1) on average, O(N) in worst case
    // Since set will contain lingest substring 128 length , 
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set;
        
        int low(0),high(0);
        int res=0;
        
        while(high<s.size() && low<s.size())
        {
            if(set.find(s[high])==set.end()){
                set.insert(s[high]);
                high++;
                int size=set.size();
                res=max(size,res);
            }
            else{
                set.erase(s[low]);
                low++;
            }
        }
        return res;
        
    }
};