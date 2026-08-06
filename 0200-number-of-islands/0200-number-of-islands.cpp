class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void bfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        q.push({r, c});
        vis[r][c] = true;

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (!vis[nr][nc] && grid[nr][nc] == '1') {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = true;

        for (int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            // Boundary check
            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            // Visit only unvisited land
            if (!vis[nr][nc] && grid[nr][nc] == '1') {
                dfs(nr, nc, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int islands = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid[i][j] == '1') {

                    islands++;

                    bfs(i, j, grid, vis);
                }
            }
        }

        return islands;
    }
};