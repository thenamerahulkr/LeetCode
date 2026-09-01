class Solution {
public:
    int solve(vector<int>& prices, int i, int k, vector<vector<int>>& dp) {
        if (i >= prices.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int profit = INT_MIN;
        if (k == 0) {
            int buy = -prices[i] + solve(prices, i + 1, 1, dp);
            int skip = solve(prices, i + 1, 0, dp);
            profit = max(buy, skip);
        } else {
            int sell = prices[i] + solve(prices, i + 2, 0, dp);
            int skip = solve(prices, i + 1, 1, dp);
            profit = max(sell, skip);
        }
        return dp[i][k] = profit;
    }
    int solveWithTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k >= 0; k--) {
                if (k == 0) {
                    int buy = -prices[i] + dp[i + 1][1];
                    int skip = dp[i + 1][0];
                    dp[i][k] = max(buy, skip);
                } else {
                    int sell = prices[i] + dp[i + 2][0];
                    int skip = dp[i + 1][1];
                    dp[i][k] = max(sell, skip);
                }
            }
        }
        return dp[0][0];
    }
    int spaceOptimization(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev1(3, 0);
        vector<int> prev2(3, 0);
        vector<int> curr(3, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k >= 0; k--) {
                if (k == 0) {
                    int buy = -prices[i] + prev1[1];
                    int skip = prev1[0];
                    curr[k] = max(buy, skip);
                }
                else {
                    int sell = prices[i] + prev2[0];
                    int skip = prev1[1];
                    curr[k] = max(sell, skip);
                }
            }
            prev2= prev1;
            prev1 = curr;
        }
        return curr[0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(prices, 0, 0, dp);
        // return solveWithTabulation(prices);
        return spaceOptimization(prices);
    }
};