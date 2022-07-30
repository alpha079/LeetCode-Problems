class Solution {
public:
    vector<int> CountFreq(string& it)
    {
        vector<int> freq(26);
        
        for(auto c: it)
        {
            freq[c-'a']++;
        }
        return freq;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        
       // vector<int> freq;
        vector<int> maxFreq(26);
        vector<string> res;
        
        for(auto& it: B)
        {
             vector<int> freq=CountFreq(it);
            for(int i=0;i<26;i++)
            {
                maxFreq[i]=max(maxFreq[i],freq[i]);
            }
        }
        
        for(auto& it:A)
        {
             vector<int>freq=CountFreq(it);
            int i=0;
            for(;i<26;i++)
            {
                if(freq[i]<maxFreq[i])
                    break;
            }
            if(i==26)res.push_back(it);
        }
        return res;
    }
};