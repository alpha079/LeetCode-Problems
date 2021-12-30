class Solution {
public:
    //Good Explaination of Time complexity:
    //https://leetcode.com/problems/all-paths-from-source-to-target/discuss/986429/Python-Iterative-DFS-with-detailed-time-complexity-and-visuals
    
    void dfs(int src, int des,vector<int>& ans, vector<vector<int>>& res,vector<vector<int>>& graph)
    {
        if(src==des)
        {
            res.push_back(ans);
            return;
        }
        for(auto it: graph[src])
        {
            ans.push_back(it);
            dfs(it,des,ans,res,graph);
            ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> ans;
        vector<vector<int>> result;
       ans.push_back(0);
        dfs(0,graph.size()-1,ans,result,graph);
        return result;
        
    }
};