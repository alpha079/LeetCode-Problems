//Time:- O(M*N)
//Space : O(1)

//Follow Up Question Comments LInk
//https://leetcode.com/problems/number-of-islands/discuss/223373/Follow-up-question%3A-Count-the-number-of-Islands-efficiently-if-the-matrix-is-super-large-and-sparse
class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    bool isValid(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')
            return false;
        return true;
    }
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j]='0';
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int _x=x + DR[k];
                int _y=y + DC[k];
                if(!isValid(grid,_x,_y))
                    continue;
                
                q.push({_x,_y});
                grid[_x][_y]='0';
                
                    
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                     island++;
                    bfs(grid,i,j);
                   
                }
            }
        }
        return island;
        
    }
};
