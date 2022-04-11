class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& A, int k) {
        int n = A.size(), m = A[0].size();
        vector<int> B; // just convert the grid array to 1D array
        vector<vector<int>> result(n, vector<int>(m)); // return array
        k %= n * m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                B.push_back(A[i][j]);
        for(int i = k; i < B.size(); i++){
            int row = i / m, col = i % m; // finding out the index 
			// in 2D array. For example, if "i" is equal to 5 (6th element) and array is 3x4
			// the 6th element of B will be placed to 
			// row = i / m = 5 / 4 = 1,   col = i % m = 5 % 4 = 1
			// So, it will be placed in result[1][1]
            result[row][col] = B[i - k];
        }
        for(int i = 0; i < k; i++){
            int row = i / m, col = i % m;
            result[row][col] = B[B.size() - k + i];
        }
        return result;
    }
};