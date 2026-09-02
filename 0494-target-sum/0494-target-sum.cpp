class Solution {
public:
    int solve(vector<int>& nums, int i, int target, int currSum,
              unordered_map<string, int>& mp) {
        // Base Case
        if (i == nums.size()) {
            if (currSum == target)
                return 1;
            return 0;
        }
        string key = to_string(i) + "_" + to_string(currSum);
        if (mp.find(key) != mp.end())
            return mp[key];
        int plus = solve(nums, i + 1, target, currSum + nums[i],mp);
        int minus = solve(nums, i + 1, target, currSum - nums[i],mp);
        return mp[key] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
        unordered_map<string, int> mp;
        return solve(nums, 0, target, 0,mp);
    }
};