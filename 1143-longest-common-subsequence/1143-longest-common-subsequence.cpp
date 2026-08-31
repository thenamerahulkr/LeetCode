class Solution {
public:
    int solveWithMemo(int i, int j, string& s1, string& s2,
                      vector<vector<int>>& dp) {

        // Base case
        if (i == s1.length() || j == s2.length())
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solveWithMemo(i + 1, j + 1, s1, s2, dp);
        }

        // Characters don't match
        return dp[i][j] = max(solveWithMemo(i + 1, j, s1, s2, dp),
                              solveWithMemo(i, j + 1, s1, s2, dp));
    }
    int solveWithTabulation(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Characters match
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // return solveWithMemo(0, 0, s1, s2, dp);
        return solveWithTabulation(s1, s2);
    }
};