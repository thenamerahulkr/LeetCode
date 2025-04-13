class Solution {
private:
    int solve(int m, int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
        // base case 
        if (m == 0 and n == 0) {
            return grid[m][n];
        }
        if (m < 0 or n < 0)
            return 1e9;
        if (dp[m][n] != -1)
            return dp[m][n];
        long long up = grid[m][n] + solve(m - 1, n,dp,grid);
        long long left = grid[m][n] + solve(m, n - 1, dp,grid);
        dp[m][n] = min(up , left);
        return dp[m][n];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int column =  grid[0].size();
        vector<vector<int>> dp(row,vector<int>(column,-1));
        return solve(row-1,column-1,dp,grid);
    }
};