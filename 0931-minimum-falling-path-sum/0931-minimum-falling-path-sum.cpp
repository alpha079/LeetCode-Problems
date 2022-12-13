class Solution {
public:
    const int inf=1e8;
    vector<vector<int>> dp,vis;
    int go(int rows, int col,vector<vector<int>>& A)
    { 
        if(rows==A.size())
             return 0;
        if(col==-1 || col==A[0].size())
            return inf;
        int &ans=dp[rows][col];
        if(vis[rows][col])
            return ans;
        
        //case I
        ans=min(ans,A[rows][col]+go(rows+1,col-1,A));
        //case 2
        ans=min(ans,A[rows][col]+go(rows+1,col,A));
        //case 3
        ans=min(ans,A[rows][col]+go(rows+1,col+1,A));
    
        vis[rows][col]=1;
    return ans;
    }
    
    
    int minFallingPathSum(vector<vector<int>>& A) {
        //corner case
        if(A.empty())
            return 0;
         int rows=A.size();
        int col=A[0].size();
        
        dp.resize(rows,vector<int>(col,INT_MAX));
        vis.resize(rows,vector<int>(col,0));
        
        int ans=INT_MAX;
        for(int i=0;i<col;i++)
        {
        ans=min(ans,go(0,i,A));
        }
        return ans;
        
    }
};