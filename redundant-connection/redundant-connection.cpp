class Solution {
public:
    
    //Mulit DFS travsersal Solution
    // We will add oedges one by one in Graph , and Call DFS on that
    
    bool dfs(vector<vector<int>>& graph,vector<bool>& vis, int curr, int par=-1)
    {
        if(vis[curr]==true)return true;
        
        vis[curr]=true;
        
        for(auto child: graph[curr])
        {
            if(child!=par && dfs(graph,vis,child,curr))
                return true;
        }
        vis[curr]=false;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1,false);
        
        for(auto e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            if(dfs(graph,vis,e[0])==true)
                return e;
        }
        return {};
        
    }
};