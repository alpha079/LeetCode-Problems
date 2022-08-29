/*
Time: O(MN * α(MN)), where M <= 300 is number of rows, N <= 300 is number of columns in the matrix.
Explanation: Using both path compression and union by size ensures that the amortized time per UnionFind operation is only α(n), which is optimal, where α(n) is the inverse Ackermann function. This function has a value α(n) < 5 for any value of n that can be written in this physical universe, so the disjoint-set operations take place in essentially constant time.
Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure or https://www.slideshare.net/WeiLi73/time-complexity-of-union-find-55858534 for more information.
Space: O(M*N)
*/







//Solution with DSU. Path Compression And Rank
class Solution {
public:
    
    int total=0;
    
    int Find(int a, vector<int>& parent)
    {
        if(a!=parent[a])
            return parent[a]=Find(parent[a],parent);
        return parent[a];
    }
    void UnionFind(vector<int>& rank,vector<int>& parent, int a, int b)
    {
        int x=Find(a,parent);
        int y=Find(b,parent);
        if(x==y)return;
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        else if(rank[x]>rank[y])
        {
             parent[x]=y;
        }
        else{
             parent[y]=x;
            rank[x]++;
        }
          total--;      
    }
    int numIslands(vector<vector<char>>& grid) {
         if(grid.size() == 0||grid[0].size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> parent(row*col,0);
        vector<int> rank(row*col,0);
        for(int k=0;k<parent.size();k++)
        {
            parent[k]=k;
        }
        total=row*col;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='0')
                    total--;
                else{
                    int cell=i*col+j;
                    if(i-1>=0 and grid[i-1][j]=='1')
                        UnionFind(rank,parent,cell,(i-1)*col+j);
                    if(j-1>=0 and grid[i][j-1]=='1')
                        UnionFind(rank,parent,cell,(i)*col+j-1);
                    
                }
            }
        }
       return total; 
    }
};