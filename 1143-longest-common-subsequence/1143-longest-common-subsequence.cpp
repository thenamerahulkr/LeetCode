class Solution {
public:
    int solveWithMemo(int i, int j, string& s1, string& s2,
                      vector<vector<int>>& dp) {
        int m = s1.length();
        int n = s2.length();
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solveWithMemo(i - 1, j - 1, s1, s2, dp);
        } else {
            return dp[i][j] = max(solveWithMemo(i - 1, j, s1, s2, dp),
                                  solveWithMemo(i, j - 1, s1, s2, dp));
        }
        return -1;
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveWithMemo(m - 1, n - 1, s1, s2, dp);
    }
};