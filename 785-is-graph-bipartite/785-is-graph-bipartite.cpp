class Solution {
public:
    bool vis[101];
    int color[101];
    
    bool dfs(int node,int val,vector<vector<int>> &graph){
        
        vis[node]=true;
        color[node]=val;
        
        for(auto child:graph[node]){
            if(!vis[child]){
                if(dfs(child,val^1,graph)==false) return false;
            }else{
                if(color[child]==color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
           bool res=dfs(i,0,graph);
            if(res==false) return false;
            }
        }
        return true;
    }
};