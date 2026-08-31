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
            return dp[i][j] =
                1 + solveWithMemo(i + 1, j + 1, s1, s2, dp);
        }

        // Characters don't match
        return dp[i][j] = max(
            solveWithMemo(i + 1, j, s1, s2, dp),
            solveWithMemo(i, j + 1, s1, s2, dp)
        );
    }

    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solveWithMemo(0, 0, s1, s2, dp);
    }
};