class Solution {
public:
    vector<int> dp;
    // int RecursiveWithMemo(vector<int>& nums, int index, vector<int>& dp){
    //     // base case
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[index] != -1) return dp[index];
    //     int churaya = nums[index] + RecursiveWithMemo(nums, index + 2, dp);
    //     int ni_churaya = 0 + RecursiveWithMemo(nums, index + 1, dp);
    //     dp[index] = max(churaya, ni_churaya);
    //     return dp[index];
    // }
    int tabulateWithSpaceOpt(vector<int>& nums) {
        int n = nums.size();
        int prev1 = 0;
        int prev2 = 0;
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            int churaya = nums[i] + prev2;
            int ni_churaya = 0 + prev1;
            ans = max(churaya, ni_churaya);
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
    int tabulateWithoutSpaceOpt(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);

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
        return tabulateWithSpaceOpt(nums);
        // return tabulateWithoutSpaceOpt(nums);
    }
};