class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int pre[n];
        pre[0] = 0;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+travel[i-1];
        }
        int ans=0;
        unordered_map<char, int> last;
        for(int i=0;i<n;i++){
            ans+=garbage[i].size();
            for(auto c:garbage[i]){
                last[c] = i;
            }
        }
        for(auto p:last){
            ans+=pre[p.second];
        }
        return ans;
    }
};