class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            auto &word = wordList[i];
            if (word == beginWord) beginIdx = i;
            if (word == endWord) endIdx = i;
        }
        
        // endWord not in wordList
        if (endIdx == -1) return {};
        
        // beginWord not in wordList, add it
        if (beginIdx == -1) {
            wordList.emplace_back(beginWord);
            beginIdx = wordList.size() - 1;
        }
        
        vector<vector<int>> adjList;
        buildGraph(wordList, adjList);
        
        // we construct distance using bfs from endIdx to beginIdx
        // and apply dfs from beginIdx to endIdx, to reduce complexity
        // i think is kind of like bi-directional bfs?
        
        int pathLen = bfs(adjList, endIdx, beginIdx);
        if (pathLen == 0) return {};
        
        vector<vector<int>> paths;
        vector<int> path;
        path.emplace_back(beginIdx);
        solve(beginIdx, endIdx, adjList, pathLen, path, paths);
        
        vector<vector<string>> res;
        for (auto &path : paths)
            res.emplace_back(buildPath(path, wordList));
        return res;
    }
private:
    vector<int> dist;
    
    void solve(
        int prevIdx, int endIdx, vector<vector<int>> &adjList,
        int pathLen, vector<int> &path, vector<vector<int>> &paths) {
        
        if (pathLen == path.size()) {
            if (path.back() == endIdx)
                paths.emplace_back(path);
            return;
        }

        for (auto &nextIdx : adjList[prevIdx]) {
            // we only follow the path from bfs(endIdx, startIdx)
            if (dist[nextIdx] != dist[prevIdx] - 1) continue;
            
            path.emplace_back(nextIdx);
            solve(nextIdx, endIdx, adjList, pathLen, path, paths);
            path.pop_back();
        }
    }
    
    vector<string> buildPath(vector<int> &path, vector<string> &wordList) {
        vector<string> res;
        for (auto &e : path)
            res.emplace_back(wordList[e]);
        return res;
    }
    
    void buildGraph(vector<string> &wordList, vector<vector<int>> &adjList) {
        int n = wordList.size();
        adjList.assign(n, vector<int>{});
        
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (isAdjacent(wordList[i], wordList[j])) {
                    adjList[i].emplace_back(j);
                    adjList[j].emplace_back(i);
                }
    }
    
    bool isAdjacent(string &s, string &t) {
        int diff = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }
    
    int bfs(vector<vector<int>> &adjList, int start, int end) {
        dist.clear();
        dist.resize(adjList.size(), INT_MAX);
        
        queue<pair<int,int>> q;
        q.emplace(make_pair(start, 1));
        dist[start] = 1;
        while (q.size()) {
            auto [u, d] = q.front();
            q.pop();
            
            for (auto &v : adjList[u]) {
                // if visited
                if (dist[v] != INT_MAX) continue;
                
                q.emplace(make_pair(v, d + 1));
                dist[v] = d + 1;
                if (v == end) return dist[v];
            }
        }
        return 0;
    }
};