class Solution {
public:
    // int solve(int n, vector<int>& dp){
    //     // base case 
    //     if(n == 1) return 1;
    //     if(n == 0) return 0;
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     // dp[n] = solve(n-2, dp) + solve(n -1, dp);
    //     int left = solve(n-2,dp);
    //     int right = solve(n-1,dp);
    //     dp[n] = left + right;
    //     return dp[n];
    // }
    int fib(int n) {
        if(n ==0 ) return 0;
        // vector<int> dp(n + 1, -1);
        // return solve(n, dp);
        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 2; i <=n; i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
    
};