class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score=0; int j=tokens.size()-1; int i=0; int temp2=INT_MAX;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i]; score++;
                i++;
            }
            else if((tokens[j]+power)>=tokens[i] && i<=j && score>0)
            {
                score--;
                power+=tokens[j];
                temp2=tokens[j]; j--; 
            }
            else break;
        }
        if(power>=temp2) score++;
        return score;
    }
};