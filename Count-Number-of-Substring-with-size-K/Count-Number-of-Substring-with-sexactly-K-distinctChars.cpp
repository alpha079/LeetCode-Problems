//Count Number of substrings with exaclty 'K' Distinct Characters

//Input1:-abc k=2 output:- 2
//input2:- aba k=2 output :- 3 (ab,ba,aba)
//Input: s = "pqpqs", k = 2
//Output: 7
//Explanation: ["pq", "pqp", "pqpq", "qp", "qpq", "pq", "qs"]


//Brute Force is to take each character and run a inner For Loop to count the substring using a visited array. TC: O(n^2)

int CountSubstringWithSizeK(string str, int n, int k)
{
	if(n==0) return 0;
	int vis[26]={0};
	int cnt=0,res=0;

	for(int i=0;i<n;i++)
	{  cnt=0;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<n;j++)
		{
			if(vis[str[j]-'a']==0)
				cnt++;

			vis[str[j]-'a']++;
			if(cnt==k)
				res++;
			if(cnt>k)break;
		}
	}
	return res;
//time complexity is O(n^2) as we are traversing the string twice
}




//Optimise:- 
//Use a unordered_map and count char, and their freq. Each time if map size crosses K, remove elements from Map.
//We have to count it for at most K char (means 0 to K distinct char ) - 0 to k-1 distinct char. This will give for K distinct Char

int mostKChars(string s, int n, int k)
{
  unordered_map<char,int> map;
  int res=0;
  int low=0;
  for(int i=0;i<n;i++)
  {
    map[str[i]]++;
       while(map.size()>k)
       { 
         //check if after removing a char at "low" pointer, its freq will be zero or not. If Zero erase that element from map
          map[s[left]]--;
         if(map[s[left]]==0)
         {
           map.erase(s[left]);
         }
         left++;
       }
    res+=i-left+1;
}
  //TC:- O(N)
  //SC:- O(N)

int CountSubstringWithSizeKOptimize(string str, int n, int k)
{
	return mostKChars(str,n,k)-mostKChars(str,n,k-1); //
	//function to caculate substrings from 0 to K - function to calculate substrings from 0 to k-1
}




















