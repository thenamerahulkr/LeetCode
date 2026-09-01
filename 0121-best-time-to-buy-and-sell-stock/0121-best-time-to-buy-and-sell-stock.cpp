class Solution {
public:
    int solve(vector<int>& prices, int i, int k, vector<vector<int>>& dp) {

        if (i == prices.size() || k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int profit = INT_MIN;
        if (k==2) {
            int buy = -prices[i] + solve(prices, i + 1, k-1, dp);
            int skip = solve(prices, i + 1, k, dp);
            profit = max(buy, skip);
            // return dp[i][canBuy] = max(buy, skip);
        }
        else if(k == 1) {
            // SELL karke transaction complete → STOP
            int sell = prices[i] + solve(prices, i + 1, k-1, dp);

            // Sell nahi kiya
            int skip = solve(prices, i + 1, k, dp);
            profit = max(sell, skip);
            // return dp[i][canBuy] = max(sell, skip);
        }
        return dp[i][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // -> k is the number of transaction
        int k = 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(prices, 0, k, dp);
    }
};