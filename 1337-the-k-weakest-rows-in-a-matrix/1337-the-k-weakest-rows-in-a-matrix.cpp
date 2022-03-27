class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> rows;
        for(int i = 0; i < mat.size(); i++){
           int left = 0 , right = mat[i].size()-1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(mat[i][mid] == 0){
                    right = mid - 1;
                } else left = mid + 1;
            }
            rows.push_back({left, i});
        }
        sort(rows.begin(), rows.end());
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(rows[i].second);
        }
        return result;
    }
};