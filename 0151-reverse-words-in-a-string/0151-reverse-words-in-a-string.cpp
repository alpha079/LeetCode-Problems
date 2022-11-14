class Solution {
public:
    string reverseWords(string s) {
        
        string result="", word="";
        int n=s.size();
        
        int i=0;
        while(i<n)
        {
            
           
            while(i<n && s[i]==' ')
            {
                i++;
            }
             word="";
            while(i<n && s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
            if(result.empty())
            {
                result=word;
                cout<<result<<endl;
            }
           else if(word.length()){ 
               cout<<word;
               result=word+ ' '+ result;
           }
            
            
        }
        return result;
        
    }
};