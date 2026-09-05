class Solution {
public:
    int doubleLoop(vector<int>& nums){
        int n = nums.size();
        vector<int> lis(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
    int solveWithMemo(int i, const vector<int>& nums, int prev, vector<vector<int>>& dp) {
        int n = nums.size();
        if (i == n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solveWithMemo(i + 1, nums, i, dp);
        }
        int skip = 0 + solveWithMemo(i + 1, nums, prev, dp);
        return dp[i][prev + 1] = max(take, skip);
    }
    int solveWithTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1, 0)); 
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = -1; prev < n; prev++) {
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }
                int skip = dp[i + 1][prev + 1];
                dp[i][prev + 1] = max(take, skip);
            }
        }
        return dp[0][0];
    }
    int spaceOptimization(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev1(n+1,0);
        vector<int> curr(n+1,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = -1; prev < n; prev++) {
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + prev1[i + 1];
                }
                int skip = prev1[prev + 1];
                curr[prev + 1] = max(take, skip);
            }
            prev1 = curr;
        }
        return prev1[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2501, vector<int>(2501, -1));
        // return solveWithMemo(0, nums, -1, dp);
        // return spaceOptimization(nums);
        return doubleLoop(nums);
    }
};