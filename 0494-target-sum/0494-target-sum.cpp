class Solution {
public:
    int solve(vector<int>& nums, int i, int target, int currSum,
              unordered_map<string, int>& mp, vector<vector<int>>& dp,
              int totalSum) {
        // Base Case
        if (i == nums.size()) {
            if (currSum == target)
                return 1;
            return 0;
        }
        // string key = to_string(i) + "+" + to_string(currSum);
        // if (mp.find(key) != mp.end())
        //     return mp[key];
        if (dp[i][currSum + totalSum] != -1)
            return dp[i][currSum + totalSum];
        int plus =
            solve(nums, i + 1, target, currSum + nums[i], mp, dp, totalSum);
        int minus =
            solve(nums, i + 1, target, currSum - nums[i], mp, dp, totalSum);
        // return mp[key] = plus + minus;
        dp[i][currSum + totalSum] = plus + minus;
        return dp[i][currSum + totalSum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * 1001, -1));
        unordered_map<string, int> mp;
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        return solve(nums, 0, target, 0, mp, dp, totalSum);
    }
};