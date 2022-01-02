class Solution {
   //Time: O(mn), the same as before
//Space: O(1), as everything is done in-place, and with O(1) extra memory.
 
    //For O(m*N) Copy the input array into another 2D array
    //vector<vector<int>> curr = board;
public:
     bool isSafe(int n, int m, int x, int y)
            {
             if(x<0 || y<0 ||x>=n || y>=m)return false;
        
              return true;
             }
    int countLiveNeigh(vector<vector<int>>& b,int i, int j)
    {
        vector<pair<int, int>>dir ={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        int live=0;
        for(auto it: dir)
                {
                    int _x=i +it.first;
                    int _y=j +it.second;
                    
                    if(isSafe(b.size(),b[0].size(),_x,_y) && (b[_x][_y]==1 or b[_x][_y]==2))
                    {
                        live++;
                    }
                }
        return live;
        
        
    }
      
    void gameOfLife(vector<vector<int>>& board) {
        
        if(!board.size()) return;
        
       
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int live=countLiveNeigh(board,i,j);
                
                if(board[i][j]==1 and (live<2 or live>3))
                {
                    board[i][j]=2;
                    //2 will resemble to 0 in answer, but this need to be used for 
                    //further cells. Because , this cell used to be 1. We made it to
                    // 2 due to the rules given
                }
                else if(board[i][j]==0 and live==3)
                {
                    board[i][j]=-1; //turm to 1(-1);
                    //we dont have to include this value anywhere else;
                }
                
            }
        }
      /*  for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<board[i][j]<<" ";
                
            }cout<<endl;
        } */
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==-1)
                    board[i][j]=1;
                else if(board[i][j]==2)
                     board[i][j]=0;
                
            }
        }
        
    }
};