
//TC:- O(M+N)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        int low=row-1;
        int high=0;
       
        int cnt=0;
       
        while(low>=0 and high<=col-1)
        {
            if(grid[low][high]<0)
            {
                cnt+=col-high;
                low--;
            }
            else high++;
        }
        return cnt;
    }
};