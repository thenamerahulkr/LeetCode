class Solution {
public:
    bool solveWithMemo(vector<int>& nums, int i, int target, int n, vector<vector<int>>& dp) {
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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1,-1));
        return solveWithMemo(nums, n - 1, target, n, dp);
    }
};