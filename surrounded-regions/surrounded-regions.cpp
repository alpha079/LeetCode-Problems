class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>&board){
        board[i][j]='/';
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int newx=i+dx[k];
            int newy=j+dy[k];
            if(newx<0 or newx>=n or newy<0 or newy>=m or board[newx][newy]!='O')continue;
            //board[newx][newy]='/';
            dfs(newx,newy,n,m,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                //we will only move in the Four Extreme Row and colums
                // to identify that this "O" connected to these point are not valid
                // So we Marking them with '/'
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    if(board[i][j]=='O'){
                        
                        dfs(i,j,n,m,board);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='/'){
                    board[i][j]='O';
                }
            }
        }
    }
};