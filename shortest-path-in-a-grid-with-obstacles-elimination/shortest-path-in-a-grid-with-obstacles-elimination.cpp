//  TC: O(mn)
//   SC: O(mn)
//

struct node{
    int r;
    int c;
    int k;
    int s;
    
    node(int _r,int _c, int _k, int _s)
    {
        r=_r;
        c=_c;
        k=_k;
        s=_s;
    }
};

class Solution {
public:
    //the only thing we are sure of is that, BFS will pick the shorest Path
    // We are not sure if it will give Min Path with K obstacles or not
    //SO, we are declaring A 2D array, which will keep track , if the current i,j has been visited with more obstacles or not
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int row=grid.size()-1;
        int col=grid[0].size()-1;
        
        //Bases Cases
        if (row == 1 && col == 1) return 0;
        if (k > row + col) return row + col;
        //Declare a memo to keep track of Obstacles made so far
        vector<vector<int>> memo (row + 1, vector<int>(col + 1, -1));
        
        //Start BFS
        queue<node> q;
        q.emplace(0,0,k,0);
        
        int res=0;
        
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--)
            {
                node curr=q.front();
                q.pop();
                
                //Check 1: If we are out of Range for i and j
                if(curr.r<0 || curr.c<0 || curr.r>row || curr.c>col)
                    continue;
                
                //check 2:- If we are at obstacles
                if(grid[curr.r][curr.c]==1)
                {
                    if(curr.k>0)
                        curr.k--;
                    else continue;
                }
                //Check 3: If we reached the goal
                if(curr.r==row && curr.c==col)
                    return curr.s;
                
                if(memo[curr.r][curr.c]>=curr.k)
                {
                    continue;
                }
                
                memo[curr.r][curr.c]=curr.k;
                
                //Now move in four directions
                 q.emplace(curr.r, curr.c + 1, curr.k,curr.s+1); // right
                q.emplace(curr.r + 1, curr.c, curr.k,curr.s+1); // down
                q.emplace(curr.r, curr.c - 1, curr.k,curr.s+1); // left
                q.emplace(curr.r - 1, curr.c, curr.k,curr.s+1); // up
            }
        }
        return -1;
         
        
    }
};