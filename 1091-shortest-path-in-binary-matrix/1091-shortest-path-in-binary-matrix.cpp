class Solution {
public:
    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        int path = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r,c] = q.front();
                q.pop();

                // Destination reached
                if (r == n-1 && c == n-1)
                    return path;

                for (int k = 0; k < 8; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n)
                        continue;

                    if (!vis[nr][nc] && grid[nr][nc] == 0) {

                        vis[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }

            path++;
        }

        return -1;
    }
};