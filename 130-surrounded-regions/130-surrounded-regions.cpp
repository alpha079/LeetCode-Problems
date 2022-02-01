
//TC:- O(N*M)
//SC:- O(N*M)
//Also, inspite of Visited array I can use The input array to mark the Border '0' with '/', anf then in last step, I can again convert it to '0'

class Solution {
public:
    void markuncapturable(vector<vector<char>> &board , vector<vector<bool>> &unmovable , int r , int c){
        int m = board.size();
        int n = board[0].size();
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] == 'X' || unmovable[r][c] == true) return;
        
        unmovable[r][c] = true;

        markuncapturable(board , unmovable , r , c + 1);
        markuncapturable(board , unmovable , r + 1, c);
        markuncapturable(board , unmovable , r - 1 , c);
        markuncapturable(board , unmovable , r , c - 1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> unmovable(m , vector<bool>(n , false));
        
        //upper boundary
        for(int c = 0 ; c < n ; c++){
            if(board[0][c] == 'O' && unmovable[0][c] != true){
                markuncapturable(board , unmovable , 0 , c);
            }
        }
        //right boundary
        for(int r = 0 ; r < m ; r++){
            if(board[r][n - 1] == 'O' && unmovable[r][n - 1] != true){
                markuncapturable(board , unmovable , r , n - 1);
            }
        }
        //lower boundary
        for(int c = n - 1 ; c >= 0 ; c--){
            if(board[m - 1][c] == 'O' && unmovable[m - 1][c] != true){
                markuncapturable(board , unmovable , m - 1 , c);
            }
        }
        //left boundary
        for(int r = m - 1 ; r >= 0 ; r--){
            if(board[r][0] == 'O' && unmovable[r][0] != true){
                markuncapturable(board , unmovable , r , 0);
            }
        }
        
        //we have marked all the 'O' island that can't be converted
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'O' && unmovable[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};