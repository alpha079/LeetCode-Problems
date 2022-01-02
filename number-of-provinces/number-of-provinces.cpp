class Solution {
public:

    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j]==1) {
                    count++;
                    
                    dfs(M, i);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& arr, int index) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[index][i]) {
                arr[index][i] = 0; // i->j
                
                arr[i][index] = 0;  //j->i
                //Set both to Zero so that we does not count twice
                dfs(arr, i);
            }
        }
    }
};