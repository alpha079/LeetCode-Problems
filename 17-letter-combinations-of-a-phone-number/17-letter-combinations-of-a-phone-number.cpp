class Solution {
public:
    
  /*
  Time Complexity : O(4^N*N), where N, is the length of input string. 4^N for building every possible string combination and N to form the string by joining each character.. Here, 4 is chosen assuming the worst case where each digit will be 7 or 9 and we would have 4*4*4*4 total string combinations.
Space Complexity : O(N), the max recursion depth will be N, where N is the length of input string. If the space required for ans is considered as well, the complexity will be O(4^N).
*/


    
   vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;   
    
   
    void helper(int index,string& str,string& path)
    {
        if(index==size(str))
        {
            ans.push_back(path);
            return;
        }
        else{
        for(auto c: mapping[str[index]-'2'])
        {
            path.push_back(c);
            helper(index+1,str,path);
            path.pop_back();
        }
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)
            return {};
        string temp="";
        helper(0,digits,temp);
        return ans;
        
    }
};