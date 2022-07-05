//try to convert this while matric into single array
//TC:- O(log(row*col)) => log(n) where is row*col

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
       int low=0,high=col-1;
        
        while(low<row and high>=0)
        {
            if(matrix[low][high]==key)
                return true;
            else if(matrix[low][high]<key)
                 low++;
            else high--;
        }
        
      
        return false;
        
    }
};