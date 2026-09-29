class Solution {
public:
    int m, n;
    int memo[101][101][210];
    bool solve(vector<vector<char>>& grid, int i, int j, int count) {
        if (i >= m || j >= n)
            return false;
            if (grid[i][j] == '(') {
            count++;
        }
        else {
            count--;
        }
        if (count < 0)
            return false;
        if(count == 0 && i == m - 1 && j == n - 1) return true;
        if (memo[i][j][count] != -1)
            return memo[i][j][count];
        bool down = solve(grid, i + 1, j, count);
        bool right = solve(grid, i, j + 1, count);
        return memo[i][j][count] = (down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;
        // if ((m + n - 1) % 2 != 0)
        //     return false;
        memset(memo, -1, sizeof(memo));
        return solve(grid, 0, 0, 0);
    }
};