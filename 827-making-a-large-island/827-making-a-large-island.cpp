/*class Solution {
public:
    //Time: O(M * N), where M <= 500 is number of rows, N <= 500 is number of columns in the matrix.
//Space: O(M * N)
    unordered_map<int,int> map;
    int id=2;
    vector<int> dir={0,1,0,-1,0};
    void dfs(vector<vector<int>>& grid, int i, int j, int& area)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
        {
            return;
        }
        area++;
        grid[i][j]=id;
        for(int k=0;k<4;k++)
        {
            int _x=i + dir[k];
            int _y=j + dir[k+1];
            dfs(grid,_x,_y,area);
        }
       
    }
    void  markAllConnectedComponents(vector<vector<int>>& grid)
    {
        map.clear();
          int row=grid.size();
          int col=grid[0].size();
          int maxArea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int area=0;
                if(grid[i][j]!=1)continue;
                 
                dfs(grid,i,j,area);
                cout<<area;
                map[id]=area;
                id++;
                
            }
        }
    }
    int FindLargestIsland(vector<vector<int>>& grid)
    {
         int row=grid.size();
          int col=grid[0].size();
           int maxArea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               
                if(grid[i][j]!=0)continue;
                
                 unordered_set<int> set;
                
                 for(int k=0;k<4;k++)
                 {
                     int _row= i+ dir[k];
                     int _col= j+ dir[k+1];
                     if(_row<0 || _row>=row || _col<0 || _col>=col || grid[_row][_col]==0)continue;
                     set.insert(grid[_row][_col]);
                 }
                int area=1;
                for(auto it: set)
                {
                  area+=map[it];
                  
                }
                maxArea=max(area,maxArea);
            }
        }
        return maxArea;
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        
      
        
        markAllConnectedComponents(grid);
        
        return FindLargestIsland(grid);
        
    }
};
*/
class Solution {

    //TC:- O(M*N)
    //Sc:- O(M*N)
// As 0,1 already occupied in matrix so we need to start with index = 2;
int idx=2;

// HashMap to have mapping between the connected component index and its area
unordered_map<int,int> mp;

// 4 directions to find out connected 1s
vector<pair<int,int>> direction{{1,0},{-1,0},{0,1},{0,-1}};

// Globally declaring the area variable which will store the max area
int area = 0;

// Simple DFS method for assigning connected components an index.
void dfs(int i,int j,vector<vector<int>> &grid)
{
    if(i<0 or i>=size(grid) or j<0 or j>=size(grid) or grid[i][j]!=1)
        return;
    mp[idx]++;
    grid[i][j]=idx;
    for(auto dir:direction)
    {
        dfs(i+dir.first,j+dir.second,grid);
    }
}

// Method to mark all the connected components.
void markAllTheConnectedComponents(vector<vector<int>>& grid)
{
    int n=size(grid);
    mp.clear();
    idx=2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                dfs(i,j,grid);
            // Here we are handling the situation when there is no 0 in the matrix.
                area=max(area,mp[idx]);
                idx++;
            }
        }
    }
}

// Method to find out the max area in case of any 0 to be flipped.
int findMaxArea(vector<vector<int>>& grid)
{
     int row=grid.size();
          int col=grid[0].size();
           int maxArea=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
               
                if(grid[i][j]!=0)continue;
                
                 unordered_set<int> set;
                
                for(auto dir:direction)
             {
           
                     int _row= i+ dir.first;
                     int _col= j+ dir.second;
                     if(_row<0 || _row>=row || _col<0 || _col>=col || grid[_row][_col]==0)continue;
                     set.insert(grid[_row][_col]);
                 }
                int maxarea=1;
                for(auto it: set)
                {
                  maxarea+=mp[it];
                  
                }
                area=max(area,maxarea);
            }
        }
        return area;
}


public:
    int largestIsland(vector<vector<int>>& grid) 
    {
//         Step 1: Mark all the connected componentes with index.
        markAllTheConnectedComponents(grid);
//         Step 2: Do BFS to find which 0 flip will result in the larger area.
        return findMaxArea(grid);
       
    }
};