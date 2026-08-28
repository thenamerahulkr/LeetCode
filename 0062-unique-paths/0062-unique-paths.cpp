class Solution {
public:
    int solveWithMemo(int m, int n, vector<vector<int>>& dp) {
        // base case
        if (m == 0 and n == 0) {
            return 1;
        }
        if (m < 0 or n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int up = solveWithMemo(m - 1, n, dp);
        int left = solveWithMemo(m, n - 1, dp);
        dp[m][n] = up + left;
        return dp[m][n];
    }
    int solveWithTabulation(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // filling first row, and first col
        for (int r = 0; r < m; r++) {
            dp[r][0] = 1;
        }
        for (int c = 0; c < n; c++) {
            dp[0][c] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    int uniquePaths(int m, int n) { return solveWithTabulation(m, n); }
};