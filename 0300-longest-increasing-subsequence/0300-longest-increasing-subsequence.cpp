class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, int n,
              vector<vector<int>>& dp) {
        // base case
        if (i == n)
            return 0;
        // take
        if (prev != -1 and dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int take = INT_MIN;
        if (prev == -1 or nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, n, dp);
        }
        int skip = 0 + solve(i + 1, prev, nums, n, dp);
        // not take
        return dp[i][prev + 1] = max(take, skip);
    }
    int solveWithTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                // take
                int take = 0;

                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                // skip
                int skip = dp[i + 1][prev + 1];

                dp[i][prev + 1] = max(take, skip);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solve(0, -1, nums, n, dp);
        return solveWithTabulation(nums);
    }
};