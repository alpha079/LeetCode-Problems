class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
        
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                        
                        if(solve(board)==true)
                            return true;
                        else board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
       
    }
    bool isValid(vector<vector<char>>& board, int r, int c, char d)
    {
        int allrow=3*(r/3);
        int allcol=3*(c/3);
        
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==d)
                return false;
            if(board[r][i]==d)
                return false;
            if(board[allrow+i/3][allcol+i%3]==d)
                return false;
        }
        return true;
        
    }
    
    
};