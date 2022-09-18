class Solution {
public:
    //PARAMETERS:
    //i & j : Ends of the array.
    //turn : 1 If turn of player A. 0 If turn of player B.
    int find(int i, int j, bool turn, vector<int> &array, vector<vector<vector<int>>> &dp){
        if(i>j) return 0;

        if(dp[i][j][turn]!=-1) return dp[i][j][turn]; 

        //PLAYER A: Maximize the score of player A.
        if(turn){
            int pathA = array[i] + find(i+1, j, 0, array, dp);
            int pathB = array[j] + find(i, j-1, 0, array, dp);
            return dp[i][j][turn] = max(pathA, pathB);
        }

        //PLAYER B: Minimize the score of player A.
        else{
            int pathA = find(i+1, j, 1, array, dp);
            int pathB = find(i, j-1, 1, array, dp);
            return dp[i][j][turn] = min(pathA, pathB);
        }
        
    }
    
    bool PredictTheWinner(vector<int>& array) {
        int i=0; int j=array.size()-1;
        int n = array.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        int pA = find(i, j, 1, array, dp);

        int total=0; for(const int &i: array) total+=i;
        int pB = total - pA;

        return (pA>=pB);
    }
};