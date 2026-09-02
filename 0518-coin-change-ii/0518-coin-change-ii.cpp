class Solution {
public:
    int solve(int i, vector<int>& nums, int k, vector<vector<int>>& dp) {
        // Base Case
        int n = nums.size();
        if (i == n or k < 0)
            return 0;
        if (k == 0)
            return 1;
        if (dp[i][k] != -1)
            return dp[i][k];
        int currTake = 0;
        int nextTake = 0;
        if (nums[i] <= k) {
            currTake = solve(i, nums, k - nums[i], dp);
        }
        nextTake = solve(i + 1, nums, k, dp);
        return dp[i][k] = currTake + nextTake;
    }
    int solveWithTabulation(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                long long currTake = 0;
                long long nextTake = 0;
                if (nums[i] <= j) {
                    currTake = dp[i][j - nums[i]];
                }
                nextTake = dp[i + 1][j];
                dp[i][j] = currTake + nextTake;
            }
        }
        return dp[0][k];
    }
    int spaceOptimization(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1, 0);
        prev[0] = 0;
        curr[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                int currTake = 0;
                int nextTake = 0;
                if (nums[i] <= j) {
                    int res = curr[j - nums[i]];
                    if (res != 0) {
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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // int ans = solve(0, coins, amount, dp);
        // return (ans == INT_MAX) ? -1 : ans;
        int ans = solveWithTabulation(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};