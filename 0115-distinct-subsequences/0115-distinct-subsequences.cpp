class Solution {
public:
    int memo[1005][1005];
    int solve(string& s, string& t, int i, int j) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i - 1] == t[j - 1]) {
            return memo[i][j] = solve(s, t, i - 1, j - 1) + solve(s, t, i - 1, j);
        } else {
            return memo[i][j] = solve(s, t, i - 1, j);
        }
    }
    long long tabulation(string s, string t){
        int m = s.length(), n = t.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return (int)dp[m][n];
    }
    int numDistinct(string s, string t) {
        memset(memo, -1, sizeof(memo));
        // return solve(s, t, s.length(), t.length());
        return tabulation(s,t);
    }
};