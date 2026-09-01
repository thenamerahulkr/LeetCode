class Solution {
public:
    bool solveWithMemo(vector<int>& nums, int i, int target, int n,
                       vector<vector<int>>& dp) {
        // base case likho
        if (target == 0)
            return true;
        if (i == 0 and target != 0)
            return false;
        if (i == 0 and target == 0)
            return true;
        if (dp[i][target] != -1)
            return dp[i][target];
        // we have two choice either take that nums[i] or skip that
        bool take = false;
        if (target >= nums[i]) {
            take = solveWithMemo(nums, i - 1, target - nums[i], n, dp);
        }
        bool skip = solveWithMemo(nums, i - 1, target, n, dp);
        return dp[i][target] = take or skip;
    }
    bool solveWithTabulation(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        // Sum 0 can always be formed by taking nothing
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // Choice 1: Exclude the current element
                bool notTake = dp[i - 1][j];

                // Choice 2: Include the current element (if it doesn't exceed
                // target)
                bool take = false;
                if (arr[i - 1] <= j) {
                    take = dp[i - 1][j - arr[i - 1]];
                }

                dp[i][j] = take || notTake;
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return solveWithMemo(nums, n - 1, target, n, dp);
        return solveWithTabulation(nums, target);
    }
};