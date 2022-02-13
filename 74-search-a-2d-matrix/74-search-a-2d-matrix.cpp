//try to convert this while matric into single array
//TC:- log(row*col) => log(n) where is row*col

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
       int low=0,high=row*col-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            int midVal=matrix[mid/col][mid%col];
            
            if(midVal==target)
            {
                return true;
            }
            else if(target>midVal)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return false;
        
    }
};