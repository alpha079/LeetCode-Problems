class Solution {
public:
    
    //O(V+E) for DFS (finding cycle in graph)
    //O(V+E) using topological sort also
    
    bool dfs(vector<vector<int>>&graph,int node,vector<int>&vis)
    {
        if(vis[node]==1)
            return true;
        vis[node]=1;
        
        for(auto it: graph[node])
        {
            if(vis[it]==1)return false;
            
            if(vis[it]==0)
            {
                 if(!dfs(graph,it,vis))return false;
                
            }
           
        }
        vis[node]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
       vector<vector<int>> List(numCourses);
        vector<int> vis(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            List[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
       
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(!dfs(List,i,vis))return false;
            }
        }
        return true;
    }
};