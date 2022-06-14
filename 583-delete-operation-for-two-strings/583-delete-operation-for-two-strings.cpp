class Solution {
public:
//Recursive Appraoch
/*
 1: if word1[i]==word2[j] then i+1, j+1
 2: if word1[i]!=word2[j], then two choices are there. 1 incremnt i 2: incmrent j
 3: i == word1.length and j == word2.length, then return 0
 4: i == word1.length || j == word2.length, return We have reached end of one word and only way to equalize is to delete rest of characters of the other word.

*/
    vector<vector<int> >dp;
    int helper(int i, int j,string &s1, string &s2)
    {
        if(i==size(s1) && j==size(s2))
            return 0;
        if(i==size(s1))
           return size(s2)-j;
        if(j==size(s2))
           return size(s1)-i;
        if(dp[i][j]!=1000)
            return dp[i][j];
        if(s1[i]==s2[j])
            return helper(i+1,j+1,s1,s2);
        return dp[i][j]=1+ min(helper(i+1,j,s1,s2),helper(i,j+1,s1,s2));
            
    }
    int minDistance(string &word1, string &word2) {
        
        dp.resize(size(word1)+1,vector<int>(size(word2)+1,1000));
        return helper(0,0,word1,word2);
        
    }
};