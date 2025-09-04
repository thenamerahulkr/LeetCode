class Solution {
public:
    int solve(int n, int i, vector<int>& dp){
        // abse case 
        if(i >= n){
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        int ek_wala = solve(n,i+1,dp);
        int do_wala = solve(n, i +2, dp);
        dp[i] = ek_wala + do_wala;
        return d[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n,1,dp);
    }
};