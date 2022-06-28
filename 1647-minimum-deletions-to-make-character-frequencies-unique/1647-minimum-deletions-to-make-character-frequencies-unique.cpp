class Solution {
public:
    //Sortting is O(26log26) = O(N)
    int minDeletions(string s) {
        vector<int> hash(26,0);
        
        for(char c: s)
        {
            hash[c-'a']++;
        }
        sort(hash.begin(),hash.end());
        //Sorted in increasing order
        int ans=0;
        //0-25, 25 is last element., we will start from 25-1= 24 element
        for(int i=24;i>=0;i--)
        {
            if(hash[i]==0)break;//this means we have completed the scan from right to left
            // just break loop and print the answer
            
            if(hash[i]>=hash[i+1])
            {
                int temp=hash[i];
                hash[i]=max(0,hash[i+1]-1);
                ans+=temp-hash[i];
            }
        }
        return ans;
    }
};