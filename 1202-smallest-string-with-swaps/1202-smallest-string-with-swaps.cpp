class Solution {
public:
    int find(int u, vector<int> &par){
        if(par[u]==-1)return u;
        return par[u] = find(par[u], par);
    }
    void merge(int u, int v, vector<int> &par, vector<int> &rank){
        int pu = find(u, par), pv = find(v, par);
        if(pu == pv)return;
        if(rank[pu] < rank[pv]){
            par[pu] = pv;
            rank[pv] += rank[pu];
        } else {
            par[pv] = pu;
            rank[pu] += rank[pv];
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> par(n,-1), rank(n,1);
        for(vector<int> edge : pairs)
            merge(edge[0], edge[1], par, rank);
        map<int, pair<vector<char>, vector<int>>>mp;
        for(int i=0; i<n; i++){
            int pi = find(i, par);
            (mp[pi].first).push_back(s[i]);
            (mp[pi].second).push_back(i);
        }
        for(auto ms : mp){
            sort(ms.second.first.begin(), ms.second.first.end());
            sort(ms.second.second.begin(), ms.second.second.end());
            int nn = ms.second.first.size();
            for(int i = 0; i<nn; i++){
                s[ms.second.second[i]] = ms.second.first[i];
            }
        }
        return s;
    }
};