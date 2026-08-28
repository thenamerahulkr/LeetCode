class Solution {
public:
    vector<int> dp;
    // int helper(vector<int>& nums, int index, vector<int>& dp){
    //     // base case
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[index] != -1) return dp[index];
    //     int churaya = nums[index] + helper(nums, index + 2, dp);
    //     int ni_churaya = 0 + helper(nums, index + 1, dp);
    //     dp[index] = max(churaya, ni_churaya);
    //     return dp[index];
    // }
    int tabulateWithoutSpaceOpt(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);

        // dp[n + 2] = 0;
        dp[n + 1] = 0;
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int churaya = nums[i] + dp[i + 2];
            int ni_churaya = 0 + dp[i + 1];
            dp[i] = max(churaya, ni_churaya);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        return tabulateWithoutSpaceOpt(nums);
    }
};