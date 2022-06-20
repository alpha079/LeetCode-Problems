//Brute Force is m*n

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        int lastNeg=col-1;
        int low=0;
        int high;
        int cnt=0;
        for(int i=0;i<row;i++)
        {
            if(grid[i][col-1]>0)
                continue;
            if(grid[i][0]<0)
            { cnt+=col;continue;}
        
        //Negative number can lie partially, either to the left of the mid, or to the right of mid
        high=lastNeg;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(grid[i][mid]>=0)
                    low=mid+1;
                else high=mid-1;
            }
            cnt+=col-low;
            lastNeg=low;
            low=0;
         }
        return cnt;
    }
};