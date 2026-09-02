class Solution {
public:
    int solveWithMemo(int i, const vector<int>& nums, int prev,
                      vector<vector<int>>& dp) {
        int n = nums.size();
        if (i == n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solveWithMemo(i + 1, nums, i, dp);
        }
        int skip = 0 + solveWithMemo(i + 1, nums, prev, dp);
        return dp[i][prev + 1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2501, vector<int>(2501, -1));
        return solveWithMemo(0, nums, -1, dp);
    }
};