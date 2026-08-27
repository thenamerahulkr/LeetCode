class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int i, bool canBuy, bool canSell,
              vector<vector<vector<int>>>& dp) {
        // Buy + Sell dono complete
        if (i == prices.size() || (!canBuy && !canSell))
            return 0;
        if (dp[i][canBuy][canSell] != -1)
            return dp[i][canBuy][canSell];
        int take = 0;
        int notTake = 0;

        if (canBuy) {
            // Buy
            take = -prices[i] + solve(prices, i + 1, false, true, dp);

            // Buy nahi kiya
            notTake = solve(prices, i + 1, true, true, dp);
        } else if (canSell) {
            // Sell
            take = prices[i] + solve(prices, i + 1, true, false, dp);

            // Sell nahi kiya
            notTake = solve(prices, i + 1, false, true, dp);
        }

        return dp[i][canBuy][canSell] = max(take, notTake);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(prices, 0, true, false, dp);
    }
};