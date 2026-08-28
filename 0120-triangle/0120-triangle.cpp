class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, int n,
              vector<vector<int>>& dp) {
        if (i == n - 1) {
            return triangle[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

        return dp[i][j] = min(down, diagonal);
    }
    int solveWithTabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int c = 0; c < n; c++) {
            dp[n - 1][c] = triangle[n - 1][c];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solveWithTabulation(triangle);
    }
};