class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
private: 
    int solve(int n , vector<int> &dp){
        if(n==0) return 0;
        if( n==1 or n==2) return 1;
        if(dp[n] != -1) return dp[n];
        int first_number = solve(n-1,dp);
        int second_number = solve(n-2,dp);
        int third_number = solve(n-3,dp);
        dp[n] = first_number+second_number+third_number;
        return dp[n];
    }
};