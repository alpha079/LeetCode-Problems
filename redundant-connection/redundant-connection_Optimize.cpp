//Code Using Dijoint Set
//TC:- O(NlogN) coz used Path Compression
//Reference:- https://leetcode.com/problems/redundant-connection/discuss/1295887/Easy-Solution-w-Explanation-or-All-Possible-Approaches-with-comments

class DSU {
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);
    }
    int find(int x) {
        if(x == par[x]) return x;           // x is itself the parent of this component
        return par[x] = find(par[x]);       // update parent of x before returning for each call
    }
    bool Union(int x, int y) {
        auto xp = find(x), yp = find(y);    // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;          // x and y already belong to same component - not possible to union
        return par[xp] = yp;                // union x and y by making parent common
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        DSU d(size(edges)+1);
        for(auto e: edges)
        {
            if(!d.Union(e[0],e[1]))
                return e;
            else continue;
            
        }
        return {};
        
    }
};
