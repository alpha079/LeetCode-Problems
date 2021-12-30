class DSU{
    vector<int> parent;
    public:
     DSU(int n):parent(n)
     {
         for(int i=0;i<n;i++)
         {
             parent[i]=i;
         }
     }
    int find(int v)
    {
        if(v==parent[v])
            return v;
        else return parent[v]=find(parent[v]);
    }
    
    void Union(int a, int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
             parent[b]=a;
     
    }
    int result(int n)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        DSU d(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++) {
            if(isConnected[i][j]==1 and i!=j)
            {
                d.Union(i,j);
            }
            }
        }
        int cnt=d.result(n);
        return cnt;
        
    }
};
