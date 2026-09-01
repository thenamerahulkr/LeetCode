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
    int solveWithTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k >= 0; k--) {
                if (k == 0) {
                    int buy = -prices[i] + dp[i + 1][1];
                    int skip = dp[i + 1][0];
                    dp[i][k] = max(buy, skip);
                } else {
                    int sell = prices[i] + dp[i + 1][0];
                    int skip = dp[i + 1][1];
                    dp[i][k] = max(sell, skip);
                }
            }
        }
        return dp[0][0];
    }
    int spaceOptimization(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(3, 0);
        vector<int> curr(3, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k >= 0; k--) {
                if (k == 0) {
                    int buy = -prices[i] + prev[1];
                    int skip = prev[0];
                    curr[k] = max(buy, skip);
                }
                else {
                    int sell = prices[i] + prev[0];
                    int skip = prev[1];
                    curr[k] = max(sell, skip);
                }
            }
            prev = curr;
        }
        return curr[0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        // return solve(prices, 0, 0, dp);
        // return solveWithTabulation(prices);
        return spaceOptimization(prices);
    }
};