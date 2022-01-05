//Take a unordered_set to keep track of the Window.
//If the window goes out, make the window in size k, by removing the element poinitng to low


string findLongestSubstring(string str, int k, int n)
{
    if(str.size()<k)
    	return str;
    int end=0,begin=0;
    unordered_set<char> s;
    int freq[128]={0};

    for(int low=0,high=0;high<n;high++)
    {
    	s.insert(str[i]);
    	freq[str[i]-'a']++;

    	while(s.size()>k)
    	{
    		if(--freq[str[low]-'a']==0)
    		{
    			s.erase[str[low]];
    		}
    		low++; // Increase the window fron left.

    	}
    	if(end-begin<high-low)
    	{
    		end=high;
    		begin=low;
    	}
    }
    return s.substr(begin,end-begin+1);
    //TC: O(N)
}
