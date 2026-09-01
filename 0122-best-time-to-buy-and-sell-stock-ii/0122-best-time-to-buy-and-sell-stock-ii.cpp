class Solution {
public:
    // TC -> O(n * k)
    // SC -> O(n * k) + O(n) recursion stack
    int solve(vector<int>& prices, int i, int k, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int profit = INT_MIN;
        if (k == 0) {
            int buy = -prices[i] + solve(prices, i + 1, 1, dp);
            int skip = solve(prices, i + 1, 0, dp);
            profit = max(buy, skip);
        } else {
            int sell = prices[i] + solve(prices, i + 1, 0, dp);
            int skip = solve(prices, i + 1, 1, dp);
            profit = max(sell, skip);
        }
        return dp[i][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(prices, 0, 0, dp);
    }
};