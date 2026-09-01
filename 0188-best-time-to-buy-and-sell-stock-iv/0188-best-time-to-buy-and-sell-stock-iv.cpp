class Solution {
public:
    // TC -> O(n*k) and SC -> O(n*k) + O(n*k);
    int solve(vector<int>& prices, int i, int k, vector<vector<int>>& dp) {
        if (i == prices.size() || k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int profit = INT_MIN;
        if (k % 2 == 0) {
            int buy = -prices[i] + solve(prices, i + 1, k - 1, dp);
            int skip = solve(prices, i + 1, k, dp);
            profit = max(buy, skip);
        } else if (k % 2 != 0) {
            int sell = prices[i] + solve(prices, i + 1, k - 1, dp);
            int skip = solve(prices, i + 1, k, dp);
            profit = max(sell, skip);
        }
        return dp[i][k] = profit;
    }
    // TC -> O(n*k) and SC -> O(n*k);
    int solveWithTabulation(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 4; k >= 1; k--) {
                if (k % 2 == 0) {
                    int buy = -prices[i] + dp[i + 1][k - 1];
                    int skip = dp[i + 1][k];
                    dp[i][k] = max(buy, skip);
                }
                if (k % 2 != 0) {
                    int sell = prices[i] + dp[i + 1][k - 1];
                    int skip = dp[i + 1][k];
                    dp[i][k] = max(sell, skip);
                }
            }
        }
        return dp[0][4];
    }
    // TC -> O(n*k) and SC -> O(4k);
    int spaceOptimization(vector<int>& prices, int k) {
        int n = prices.size();
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 4; k >= 1; k--) {
                if (k % 2 == 0) {
                    int buy = -prices[i] + prev[k - 1];
                    int skip = prev[k];
                    curr[k] = max(buy, skip);
                }
                if (k % 2 != 0) {
                    int sell = prices[i] + prev[k - 1];
                    int skip = prev[k];
                    curr[k] = max(sell, skip);
                }
            }
            prev = curr;
        }
        return curr[4];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // -> k is the number of transaction
        // int k = 4;
        int new_k = k * 2;
        vector<vector<int>> dp(n, vector<int>(new_k + 1, -1));
        return solve(prices, 0, new_k, dp);
        // return solveWithTabulation(prices, k);
        // return spaceOptimization(prices, k);
    }
};