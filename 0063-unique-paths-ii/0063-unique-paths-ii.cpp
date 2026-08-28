class Solution {
private:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp) {
        // base case
        if (m >= 0 and n >= 0 and obstacleGrid[m][n] == 1)
            return 0;
        if (m == 0 and n == 0) {
            return 1;
        }
        if (m < 0 or n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        // int up =
        // int left = solve(m, n - 1,obstacleGrid, dp);
        // dp[m][n] = up + left;
        return dp[m][n] = solve(m - 1, n, obstacleGrid, dp) +
                          solve(m, n - 1, obstacleGrid, dp);
        ;
    }
    int solveWithTabulation(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // filling first row, and first col
        if (obstacleGrid[0][0] == 1)
            return 0;

        bool foundOne = false;
        for (int r = 0; r < n; r++) {
            if (obstacleGrid[0][r] == 1) {
                foundOne = true;
            }
            if (!foundOne) {
                dp[0][r] = 1;
            } else {
                dp[0][r] = 0;
            }
        }
        foundOne = false;
        for (int c = 0; c < m; c++) {
            if (obstacleGrid[c][0] == 1) {
                foundOne = true;
            }
            if (!foundOne) {
                dp[c][0] = 1;
            } else {
                dp[c][0] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // int m = obstacleGrid.size();
        // int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(m-1,n-1,obstacleGrid,dp);
        return solveWithTabulation(obstacleGrid);
    }
};