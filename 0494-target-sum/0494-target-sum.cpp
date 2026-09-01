class Solution {
public:
    int solve(vector<int>& nums, int i, int target) {
        // Base Case
        if (i == nums.size()) {
            if (target == 0)
                return 1;
            return 0;
        }
        int plus = solve(nums, i + 1, target + nums[i]);
        int minus = solve(nums, i + 1, target - nums[i]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int k = target;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(nums, 0, k);
    }
};