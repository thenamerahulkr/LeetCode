class Solution {
public:
    int solve(int i, vector<int>& nums, int k, vector<vector<int>>& dp) {
        // base case
        int n = nums.size();
        if (i == n or k < 0)
            return INT_MAX;
        if (k == 0)
            return 0;
        if(dp[i][k] != -1) return dp[i][k];
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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(0, coins, amount, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};