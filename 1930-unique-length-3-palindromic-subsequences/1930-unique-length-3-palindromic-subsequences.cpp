class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> unique_letters;// create a map to find unique char in string
        
        for(char &ch : s) {
            unique_letters.insert(ch);// find set size , which gives unique char in s
        }
        int result = 0;
        for(char letter : unique_letters) {
            
            int first_idx = -1;// find 1st and last occurence of every char 
            int last_idx  = -1;// initialize -1 at starting 
            for(int i = 0; i<n; i++) {
                if(s[i] == letter) {
                    
                    if(first_idx == -1) {//if we not find 1st letter then we update 
                        first_idx = i;
                    }
                    last_idx = i; 
                }
            }
                          
            unordered_set<char> st; // iterates between 1st & last occurence 
            for(int middle = first_idx+1; middle <= last_idx-1; middle++) {
                st.insert(s[middle]);// 
            }
            result += st.size();//count of unique char between same 2 charcters will be result  
        }
        return result;
    }
};