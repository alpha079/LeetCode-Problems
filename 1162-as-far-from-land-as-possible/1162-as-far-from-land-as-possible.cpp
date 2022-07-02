class Solution {
public:
    
    //We have Source= Land(1) Mulitple Sources
    //Destination: One or more
    // Brute Force will be either apply Normal DFS/BFS TC:- O(M*N*N)
    //We use Multisoruce BFS
    //Pushing All Sources into the Queue(For this Question only), otherwise
    // It differ, what to push into the queue
    bool isValid(int r, int c,vector<vector<int>>& grid)
    {
        return r>=0 and c>=0 and r<grid.size() and c<grid[0].size();
    }
    int maxDistance(vector<vector<int>>& grid) {
         vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        int steps=0;
        while(!q.empty())
        {
            
            int size=q.size();
            while(size--)
            {
                auto [r,c]=q.front();
                q.pop();
                if(grid[r][c]>1)
                {
                    steps=grid[r][c];
                }
                
                for(auto it:dir)
                {
                    int newX= r + it[0];
                    int newY= c + it[1];
                    if(isValid(newX,newY,grid) && grid[newX][newY]==0)
                    {
                        grid[newX][newY]=grid[r][c]+1;
                        q.push({newX,newY});
                    }
                }
                
                
            }
        }
        return steps-1;
    }
};