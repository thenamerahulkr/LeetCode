class Solution {
public:
    int solve(int i, string& s, int k, int prev, vector<vector<int>>& dp) {
        int n = s.length();
        if (i == n)
            return 0;
        int take = 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        if (prev == '\0' or abs(s[i]  - prev) <= k) {
            take = 1 + solve(i + 1, s, k, s[i], dp);
        }
        int skip = 0 + solve(i + 1, s, k, prev, dp);
        return dp[i][prev] = max(take, skip);
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(123, -1));
        return solve(0, s, k, '\0',dp);
    }
};