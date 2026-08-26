class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        // Base case: boundary check or empty gold cell
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        // Store current cell's gold and mark it as visited (0)
        int currentGold = grid[r][c];
        grid[r][c] = 0;

        // Explore all 4 directions
        int maxFutureGold = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            maxFutureGold = max(maxFutureGold, dfs(grid, r + dr[i], c + dc[i], m, n));
        }

        // Backtrack: restore the cell's gold value
        grid[r][c] = currentGold;

        return currentGold + maxFutureGold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;

        // Try starting DFS from every cell containing gold
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(grid, i, j, m, n));
                }
            }
        }

        return maxGold;
    }
};