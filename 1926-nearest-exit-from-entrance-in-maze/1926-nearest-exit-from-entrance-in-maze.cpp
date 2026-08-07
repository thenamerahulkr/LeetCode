class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int level_bfs(vector<vector<char>>& maze, int sr, int sc) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        maze[sr][sc] = '+';
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                // here we can check the condition for out or exit
                // if hai toh yhi se return krenge dist ni toh
                if (!(r == sr && c == sc) &&
                    (r == 0 || r == m - 1 || c == 0 || c == n - 1)) {
                    return dist;
                }
                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (maze[nr][nc] == '.') {
                        maze[nr][nc] = '+'; // marking visited
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int sr = entrance[0];
        int sc = entrance[1];
        return level_bfs(maze, sr, sc);
    }
};