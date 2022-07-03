class Solution {
public:
	int maxRepeating(string s, string w) {
		int k=0;
		string str=w;
		while(s.find(str)!=-1){
			str+=w;
            cout<<str<<endl;
			k++;
		}
		return k;
	}
};