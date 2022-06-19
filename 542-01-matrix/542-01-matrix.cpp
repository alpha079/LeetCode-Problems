//https://leetcode.com/problems/01-matrix/discuss/2007737/JAVA-ororBFS-oror-BRUTE-FORCE-TO-OPTIMAL

//TC:- O(N*M)
class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& mat)
    {
        if(x>=mat.size() || y>=mat[0].size() || x<0 || y<0 || mat[x][y]!=-1)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        if(n==0 || m==0)
            return mat;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else mat[i][j]=-1;
            }
        }
       vector<pair<int,int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            auto it=q.front();
            int x=it.first;
            int y=it.second;
            q.pop();
            
            for(auto dir: dirs)
            {
                int newx=x + dir.first;
                int newy= y + dir.second;
                
                if(isValid(newx,newy,mat))
                {
                    mat[newx][newy]=mat[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
        return mat;
    }
};