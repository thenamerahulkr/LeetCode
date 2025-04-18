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
    int longest_common(string a, string b) {
        vector<vector<int>> dp(a.length() + 1, vector(b.length(), -1));
        return solve(a, b, a.length() - 1, b.length() - 1,
        dp);
    }
public:
    int minDistance(string word1, string word2) {
        int result = longest_common(word1, word2);
        int m = word1.length();
        int n = word2.length();
        return n+m- 2*result;
    }
};