class Solution {
private:
    void bfs(int startR, int startC, vector<vector<char>>& board, int m, int n) {
        queue<pair<int, int>> q;
        
        // Push starting boundary 'O' and mark visited
        q.push({startR, startC});
        board[startR][startC] = '#';
        
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nr = r + dRow[k];
                int nc = c + dCol[k];
                
                // If neighbor is valid and is 'O', mark and push to queue
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        
        // 1. Loop through boundary and trigger BFS for each 'O' found
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Check if it's on the boundary
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        // Launch an independent BFS for this specific boundary cell
                        bfs(i, j, board, m, n);
                    }
                }
            }
        }
        
        // 2. Final state cleanup
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded, so captured
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // Saved from boundary connection
                }
            }
        }
    }
};