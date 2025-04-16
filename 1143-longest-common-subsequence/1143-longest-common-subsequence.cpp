class Solution {
private:
    int solve(string &a, string &b, int i, int j,vector<vector<int>> &dp){
        // base case
        if(i <0 ) return 0;
        if( j<0) return 0;

        //if string match 
        if(dp[i][j] != -1) return dp[i][j];
        int longest_common = 0;
        if(a[i] == b[j]){
            longest_common = 1 + solve(a,b,i-1,j-1,dp);
        }
        else{
            longest_common = max(solve(a,b,i-1,j,dp),solve(a,b,i,j-1,dp));
        }
        dp[i][j] = longest_common;
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector(text2.length(),-1));
        return solve(text1,text2,text1.length()-1,text2.length()-1);
    }
};