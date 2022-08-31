class Solution {
public:
    
    void DFS(vector<vector<int>>& graph, int i, int j, int prev, vector<vector<int>>& ocean)
    {
        if(i<0|| i>=graph.size() || j<0 ||j>=graph[0].size())
            return;
        if(ocean[i][j]==1)
            return;
        if(graph[i][j]<prev)
        {
            return;
        }
        ocean[i][j]=1;
        DFS(graph,i+1,j,graph[i][j],ocean);
        DFS(graph,i,j+1,graph[i][j],ocean);
        DFS(graph,i-1,j,graph[i][j],ocean);
        DFS(graph,i,j-1,graph[i][j],ocean);
        return;
        
        
        
        
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int size=heights.size();
        
        vector<vector<int>> ans;
        if(size<1)
        {
            return ans;
        }
        vector<vector<int>>pacific(heights.size(),vector<int>(heights[0].size(),0));
          vector<vector<int>>atlantic(heights.size(),vector<int>(heights[0].size(),0));
        
       //Call DFS and fill the Pacific and Atlantic Ocean taken
        
        for(int i=0;i<heights[0].size();i++)
        {
            DFS(heights,0,i,INT_MIN,pacific);
            DFS(heights,heights.size()-1,i,INT_MIN,atlantic);
        }
        for(int j=0;j<heights.size();j++)
        {
            DFS(heights,j,0,INT_MIN,pacific);
            DFS(heights,j,heights[0].size()-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    vector<int> v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }
        return ans;
       
        
    }
};