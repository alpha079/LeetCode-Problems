class Solution {
public:
     bool isValid(int r, int c,vector<vector<int>>& grid)
    {
        return r>=0 and c>=0 and r<grid.size() and c<grid[0].size();
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        
         vector<vector<int>> res;
         vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
          int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    q.push({i,j});
                }
                else{
                    grid[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto[r,c]=q.front();
                q.pop();
                for(auto it: dir)
                {
                    int newX= r+ it[0];
                    int newY= c+ it[1];
                    if(isValid(newX,newY,grid) and grid[newX][newY]==-1)
                    {
                        q.push({newX,newY});
                        grid[newX][newY]=grid[r][c]+1;
                    }
                }
            }
        }
        return grid;
        
    }
};