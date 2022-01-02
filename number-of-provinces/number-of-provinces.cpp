class Solution {
public:
    
    int Find(int x,vector<int>& parent)
    {
        if(x==parent[x])
            return x;
        return parent[x]=Find(parent[x],parent);
    }
    int findCircleNum(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        vector<int> parent(grid.size(),0);
        for(int k=0;k<grid.size();k++)
        {
            parent[k]=k;
        }
        int group=grid.size();
        for(int i=0;i<grid.size();i++)
        {
            for(int j=i+1;j<grid.size();j++)
            {
                if(grid[i][j])
                {
                    int parent1=Find(i,parent);
                    int parent2=Find(j,parent);
                    if(parent1!=parent2)
                    {
                        parent[parent2]=parent1;
                        group--;
                    }
                    
                   
                }
            }
        }
        return group;
        
    }
};