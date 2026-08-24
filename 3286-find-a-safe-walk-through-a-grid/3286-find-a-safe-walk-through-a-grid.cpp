class Solution {
public:
    int m, n;
    vector<vector<int>> best;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& grid, int x, int y, int cost) {

        // Already found a better/equal path
        if (cost >= best[x][y])
            return;

        best[x][y] = cost;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            int newCost = cost + grid[nx][ny];

            dfs(grid, nx, ny, newCost);
        }
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        m = grid.size();
        n = grid[0].size();

        best.assign(m, vector<int>(n, INT_MAX));

        dfs(grid, 0, 0, grid[0][0]);

        return best[m - 1][n - 1] < health;
    }
};