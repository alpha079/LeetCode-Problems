class Solution {
public:
    
    //concept   now, invert the matrx
              
    //3 2 1       3 1 2     now compare both the matrix
    //1 7 6       2 7 7
    // 2 7 7      1 6 7 
    int equalPairs(vector<vector<int>>& grid) {
        
        
        int row=grid.size();
        
        vector<vector<int>> mat;
        
        for(int i=0;i<row;i++)
        {
            vector<int> temp;
            for(int j=0;j<row;j++)
            {
                temp.push_back(grid[j][i]);
            }
            mat.push_back(temp);
        }
        int count=0;
        for(auto it: grid)
        {
            for(auto it1: mat)
            {
                if(it==it1)
                    count++;
            }
        }
        return count;
    }
};