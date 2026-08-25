class Solution {
public:
    int recWithMemo(int n, vector<int>& dp) {
        if (n == 1)
            return dp[n] = 1;
        if (n == 0)
            return dp[n] = 0;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = recWithMemo(n - 1, dp) + recWithMemo(n - 2, dp);
        // return dp[n];
    }
    int fib(int n) {
        vector<int> dp(31, -1);
        return recWithMemo(n, dp);
    }
};