class Solution {
public:
    int solve(int i, vector<int>& nums, int k, vector<vector<int>>& dp) {
        // base case
        int n = nums.size();
        if (i == n or k < 0)
            return INT_MAX;
        if (k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int currTake = INT_MAX;
        int nextTake = INT_MAX;
        if (nums[i] <= k) {
            int res = solve(i, nums, k - nums[i], dp);
            // Prevent integer overflow if res is INT_MAX
            if (res != INT_MAX) {
                currTake = 1 + res;
            }
        }
        nextTake = 0 + solve(i + 1, nums, k, dp);
        return dp[i][k] = min(currTake, nextTake);
    }
    int solveWithTabulation(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                int currTake = INT_MAX;
                int nextTake = INT_MAX;
                if (nums[i] <= j) {
                    int res = dp[i][j - nums[i]];
                    if (res != INT_MAX) {
                        currTake = 1 + res;
                    }
                }
                nextTake = dp[i + 1][j];
                dp[i][j] = min(currTake, nextTake);
            }
        }
        return dp[0][k];
    }
    int spaceOptimization(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prev(k + 1, INT_MAX);
        vector<int> curr(k + 1, INT_MAX);
        prev[0] = 0;
        curr[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                int currTake = INT_MAX;
                int nextTake = INT_MAX;
                if (nums[i] <= j) {
                    int res = curr[j - nums[i]];
                    if (res != INT_MAX) {
                        currTake = 1 + res;
                    }
                }
                nextTake = prev[j];
                curr[j] = min(currTake, nextTake);
            }
            prev = curr;
        }
        return curr[k];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // int ans = solve(0, coins, amount, dp);
        // return (ans == INT_MAX) ? -1 : ans;
        int ans = spaceOptimization(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};