class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int newIndex = (i * n + j + k) % total;
                int newRow = newIndex / n;
                int newCol = newIndex % n;
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};