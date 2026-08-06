class Solution {
public:
    typedef pair<int, int> p;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int bfs(queue<p>& q, vector<vector<int>>& grid, int& fresh) {
        int minutes = 0;
        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            while (size--) {

                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {

                    int nr = r + dx[k];
                    int nc = c + dy[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int number_of_fresh = 0;
        queue<p> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    number_of_fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        return bfs(q, grid, number_of_fresh);
    }
};