class Solution {
public:
    int solve(vector<int>& nums, int i, int target, int currSum) {
        // Base Case
        if (i == nums.size()) {
            if (currSum == target)
                return 1;
            return 0;
        }
        int plus = solve(nums, i + 1, target, currSum + nums[i]);
        int minus = solve(nums, i + 1, target, currSum - nums[i]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
        return solve(nums, 0, target, 0);
    }
};