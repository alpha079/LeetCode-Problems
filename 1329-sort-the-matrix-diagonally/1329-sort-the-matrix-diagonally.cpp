class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // There are a total of m+n-1 diagonals, so using a fast sorting
        // algorithm to sort each diagonal will take
        // O((m+n)nlogn), where n is the bigger dimension of the two
        // Sorting everything in-place will have O(1) complexity, while using
        // an auxiliary vector will have O(n) complexity
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> answer(m, vector<int>(n));
        vector<int> aux;  // This bumps up space complexity from O(1) to O(n)
        
        // Iterate over diagonals starting at first row
        for (int j = 0; j < n; ++j) {
            // Fill the aux vector with the diagonal elements
            for (int i = 0, k = j; i < m && k < n; ++i, ++k)
                aux.push_back(mat[i][k]);
            
            // Sort the diagonal in the aux vector
            sort(aux.begin(), aux.end());
            
            // Write to the answer
            for (int i = 0, k = j; i < m && k < n; ++i, ++k)
                answer[i][k] = aux[i];
            
            aux.clear();
        }
        
        // Iterate over diagonals starting at first column
        
        for (int i = 1; i < m; ++i) {
            // Fill the aux vector with the diagonal elements
            for (int k = i, j = 0; k < m && j < n; ++k, ++j)
                aux.push_back(mat[k][j]);
            
            // Sort the diagonal in the aux vector
            sort(aux.begin(), aux.end());
            
            // Write to the answer
            for (int k = i, j = 0; k < m && j < n; ++k, ++j)
                answer[k][j] = aux[j];
            
            aux.clear();            
        }
        
        return answer;
    }
};