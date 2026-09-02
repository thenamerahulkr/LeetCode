class Solution {
public:
    int solve(int i, string& s, int k, int prev, vector<vector<int>>& dp) {
        int n = s.length();
        if (i == n)
            return 0;
        int take = 0;
        if (dp[i][prev - 'a'] != -1)
            return dp[i][prev - 'a'];
        if (prev == '{' or abs(s[i] - prev) <= k) {
            take = 1 + solve(i + 1, s, k, s[i], dp);
        }
        int skip = 0 + solve(i + 1, s, k, prev, dp);
        return dp[i][prev - 'a'] = max(take, skip);
    }
    // int solveWithTabulation(string& s, int k) {
    //     int n = s.length();
    //     vector<vector<int>> dp(n + 1, vector<int>(123, 0));
    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int j = 0; j <= 123; j++) {
    //             if (prev == '\0' or abs(s[i] - prev) <= k) {
    //                 take = 1 + solve(i + 1, s, k, s[i], dp);
    //             }
    //             int skip = 0 + solve(i + 1, s, k, prev, dp);
    //             return dp[i][prev] = max(take, skip);
    //         }
    //     }
    //     return dp[0][];
    // }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(27, -1));
        return solve(0, s, k, '{', dp);
    }
};