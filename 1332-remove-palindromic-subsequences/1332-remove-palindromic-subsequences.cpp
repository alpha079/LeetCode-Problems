class Solution {
public:
    int removePalindromeSub(string s) {
        
        
    //Maximum number of steps that can be taken is 2
    int low=0;
        int high=s.size()-1;
        
        while(low<high)
        {
            if(s[low]!=s[high])return 2;
            low++;
            high--;
        }
        return 1;
    }
};