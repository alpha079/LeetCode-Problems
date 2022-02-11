class Solution {
public:
   // Time: O(M*N), where M <= 10 is number of rows, N <= 10 is number of columns in the matrix.
//Extra space (without counting output as space): O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        vector<int> res;
        while(true)
        {
            for(int i=top;i<=right;i++)
            {
                res.push_back(matrix[top][i]);
                
            }
            if(++top>bottom)
            {
                return res;
            }
            
            for(int i=top;i<=bottom;i++)
            {
                res.push_back(matrix[i][right]);
            }
            if(--right<left)
            {
                return res;
            }
            for(int i=right;i>=left;i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            if(--bottom<top)
            {
                return res;
            }
            for(int i=bottom;i>=top;i--)
            {
                res.push_back(matrix[i][left]);
            }
            if(++left>right)
            {
                return res;
            }
        }
        return res;
        
    }
};