class Solution {
private:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i < 0)
            return 0;
        if (j < 0)
            return 0;

        // if string match
        if (dp[i][j] != -1)
            return dp[i][j];
        int longest_common = 0;
        if (a[i] == b[j]) {
            longest_common = 1 + solve(a, b, i - 1, j - 1, dp);
        } else {
            longest_common =
                max(solve(a, b, i - 1, j, dp), solve(a, b, i, j - 1, dp));
        }
        dp[i][j] = longest_common;
        return dp[i][j];
    }
    int tabular(string& a, string& b, vector<vector<int>>& dp) {
        for (int j = 0; j <= b.size(); j++) {
            dp[0][j] = 0;
        }
        for (int j = 0; j <= a.size(); j++) {
            dp[j][0] = 0;
        }
        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[a.size()][b.size()];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector(text2.length(), -1));
        // return solve(text1, text2, text1.length() - 1, text2.length() - 1, dp);
        vector<vector<int>> dp1(text1.length() + 2, vector(text2.length()+2, -1));
        return tabular(text1, text2,dp1);
    }
};