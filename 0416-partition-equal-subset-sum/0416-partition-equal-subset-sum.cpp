class Solution {
private: 
    bool solve(vector<int>& nums, int target, int index,vector<vector<int>> &dp){
        // base case 
        if(target ==0 )return true;
        if(index == 0 ){
            return target == nums[0];
        }
        //not take
        if(dp[index][target] != -1)return dp[index][target];
        bool not_take = solve(nums,target,index-1,dp);
        bool take = false;
        if(nums[index]<=target){
            take = solve(nums, target-nums[index],index-1,dp);
        }
        dp[index][target]= not_take or take;
        return dp[index][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(205,vector<int>(sum/2+1,-1));
        return solve(nums,sum/2,nums.size()-1,dp);
    }
};