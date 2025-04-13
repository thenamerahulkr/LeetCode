class Solution {
private:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        // base case
        if(m >= 0 and n >= 0 and obstacleGrid[m][n] == 1) return 0;
        if (m == 0 and n == 0) {
            return 1;
        }
        if (m < 0 or n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int up = solve(m - 1, n, obstacleGrid,dp);
        int left = solve(m, n - 1,obstacleGrid, dp);
        dp[m][n] = up + left;
        return dp[m][n];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};