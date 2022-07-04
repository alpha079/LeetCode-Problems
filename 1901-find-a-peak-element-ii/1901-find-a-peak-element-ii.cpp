class Solution {
public:
    //O(nlogm)
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0;
        int high=n;
        
        while(low<=high)
        {
            int mid= low+ (high-low)/2; //column selected
            
            //now traversing the row
            int ele=0;
            int col=0;
            for(int i=0;i<m;i++)
            {
                if(ele<mat[mid][i])
                {
                    ele=mat[mid][i];
                    col=i;
                }
            }
            //now check for Top/Down
            
            int top=(mid==0)?-1:mat[mid-1][col];
            int bot= (mid==n-1)?-1:mat[mid+1][col];
            
            if(ele>top and ele>bot)
            {
                return {mid,col};
            }
            else if(ele>top and ele<bot)
            {
                low=mid+1;
            }
            else high=mid-1;
            
            
        }
        
       
        return {0,0};
    }
};