class Solution {
    // int ans = 0;
    vector<int> dp;
    int helper(vector<int>& nums, int index, vector<int>& dp){
        // base case 
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int churaya = nums[index] + helper(nums, index + 2, dp);
        int ni_churaya = helper(nums, index + 1, dp);
        dp[index] = max(churaya, ni_churaya);
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size()+1, -1);

        return helper(nums, 0, dp);
    }
};