class Solution {
    int rows;
    int cols;

private:
    bool canWeGo(int nr, int nc, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
            return true;
        return false;
    }
    int bfs(int i, int j, vector<vector<int>>& grid) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        int area = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (canWeGo(nr, nc, grid)) {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                    area++;
                }
            }
        }
        return area;
    }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return 0;
        }
        int area = 1;
        grid[i][j] = 0;
        // up
        area += dfs(i - 1, j, grid);
        // down
        area += dfs(i + 1, j, grid);
        // left
        area += dfs(i, j - 1, grid);
        // right
        area += dfs(i, j + 1, grid);
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int max_area = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    int area = dfs(row, col, grid);
                    max_area = max(area, max_area);
                }
            }
        }
        return max_area;
    }
};