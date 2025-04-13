class Solution {
private: 
    int ways_to_climb(int n, vector<int> &dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = ways_to_climb(n - 1,dp) + ways_to_climb(n - 2,dp);  
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return ways_to_climb(n,dp);
    }
};
