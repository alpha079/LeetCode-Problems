class Solution {
public:
//Recursive Appraoch
/*
 1: if word1[i]==word2[j] then i+1, j+1
 2: if word1[i]!=word2[j], then two choices are there. 1 incremnt i 2: incmrent j
 3: i == word1.length and j == word2.length, then return 0
 4: i == word1.length || j == word2.length, return We have reached end of one word and only way to equalize is to delete rest of characters of the other word.

//Recursion TC:- Time Complexity : O(2^L1 + 2^L2), where L1 is the length of string word1 and L2 is the length of string word2. Since L1 < L2 means 2^L1 < 2^L2 & vice-versa, the time complexity can be also written as O(2^max(L1,L2)).
Space Complexity : O(max(L1, L2))

Recursion + Memo :- Time Complexity : O(L1*L2)
Space Complexity : O(L1*L2)
*/
    vector<vector<int> >dp;
    int helper(int i, int j,string &s1, string &s2)
    {
        if(i==size(s1) && j==size(s2))
            return 0;
        if(i==size(s1))
           return size(s2)-j; //Value need to be deletd from the other string
        if(j==size(s2))
           return size(s1)-i; //Value need to be deletd from the other string
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