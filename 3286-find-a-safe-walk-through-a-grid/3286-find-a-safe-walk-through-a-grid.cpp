class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        // dist[i][j] = minimum health loss to reach (i,j)
        vector<vector<int>> dist(
            m, vector<int>(n, INT_MAX)
        );
        queue<pair<int,int>> q;

        dist[0][0] = grid[0][0];
        q.push({0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                int newCost = dist[x][y] + grid[nx][ny];

                // Better path found
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    q.push({nx, ny});
                }
            }
        }

        return dist[m-1][n-1] < health;
    }
};