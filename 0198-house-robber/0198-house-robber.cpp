class Solution {
    vector<int> dp;
private:
    int solve(vector<int>& nums, int index,vector<int> &dp){
        // base case 
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0],nums[1]);
        if(index < 0)  return 0;
        // take
        if(dp[index] != -1) return dp[index]; 
        int loot = nums[index] + solve(nums,index-2,dp);
        // not take
        int not_loot = 0 + solve(nums, index-1,dp);
        dp[index] = max(not_loot,loot);
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(101,-1);
        int n = nums.size();
        return solve(nums,n-1,dp);
    }
};