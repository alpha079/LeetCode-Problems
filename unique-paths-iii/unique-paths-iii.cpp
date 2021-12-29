class Solution {
public:
    
    /*
    Time Complexity:

O(R*C) ==> To find the start, end, & number of non-obstacle squares.
O(4 * 3^(NonObstacleCells-2)) ==> DFS Helper will explore all possible paths. At each square (except start & end) we will explore at most 3 directions. At start we will explore 4 directions and at end we will stop the further exploration of that path. Here the number of non-obstacle cells is bounded by R*C.
Thus worst case Time Complexity = O(RC + 4 * 3^(RC - 2)) = O(3^(RC))
Space Complexity:

O(NonObstacleCells) --> For recursion stack. Here the number of non-obstacle cells is bounded by R*C.
Thus worst case Space Complexity = O(R*C)

*/
    int uniquePathsIII(vector<vector<int>>& grid) {
        // we'll count the zeros to track 
        // if all zeros have been visited (the zero_count will be less than 0)
        int zero_count = 0;
        int start_x = 0, start_y = 0; // for storing start co-ordinates.
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) { // 1 is start
                    start_x = i;
                    start_y = j;
                    zero_count++;
                }
                if (grid[i][j] == 0) { // count the zeros...
                    zero_count++;
                }
            }
        }
        
        return dfs(grid, zero_count, start_x, start_y);
    }
    
    int dfs(vector<vector<int>>& grid, int empties, int x, int y) {
        // check out of grid bounds
        // if cell is an obstacle then get out of the recursion
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }
        
        // 2 means ending cell... reaching ending cell is not enough
        // you have to be sure the you have visited all non-obstacle
        // that's why check if zero_count is less than zero
        if (grid[x][y] == 2) {
            return empties == 0 ? 1 : 0;
        }
        
        // mark the cell
        grid[x][y] = -1;
        
        empties--;
        
        // traverse 4 directionally
        int all = dfs(grid, empties, x + 1, y) + dfs(grid, empties, x - 1, y) + dfs(grid, empties, x, y + 1) + dfs(grid, empties, x, y - 1);
        
        // undo the move to track a different path if this path is not satisfactory
        grid[x][y] = 0;
        empties++;
        
        return all;
        
    }
};
