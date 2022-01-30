class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n=num.size();
        if(k==n)return "0";
        
        
        stack<char> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(num[i]);
            }
            else{
                
                while(!s.empty() && s.top()>num[i] && k>0)
                {
                    k--;
                    s.pop();
                }
                s.push(num[i]);
            }
        }
    // Ex: "12345", k=3
	// For the above example, while inserting the elements, no element will be popped
	// But we need to remove 'k' characters 
	// Hence remove the top k characters
        while(k!=0)
        {
            s.pop();
            k--;
        }
        
    //Empty the stack to get the number;
        string ans="";
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        cout<<ans;
        
        // Removing leading zeroes
	while(ans.length() > 0 && ans[0] == '0'){
		ans.erase(0, 1);
	}
        return ans.empty() ?"0" :ans;
        
    }
};