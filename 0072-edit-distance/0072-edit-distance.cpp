class Solution {
public:
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i == word1.length())
            return word2.length() - j;
        if (j == word2.length())
            return word1.length() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) {
            return solve(word1, word2, i + 1, j + 1, dp);
        }
        int insertOp = 1 + solve(word1, word2, i, j + 1, dp);
        int deleteOp = 1 + solve(word1, word2, i + 1, j, dp);
        int replaceOp = 1 + solve(word1, word2, i + 1, j + 1, dp);

        dp[i][j] = min({insertOp, deleteOp, replaceOp});
        return dp[i][j];
    }
    int tabulation(string word1, string word2){
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][n] = m - i; 
        }
        for (int j = 0; j <= n; j++) {
            dp[m][j] = n - j; 
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int insertOp  = dp[i][j + 1];     
                    int deleteOp  = dp[i + 1][j];    
                    int replaceOp = dp[i + 1][j + 1]; 
                    
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1 , vector<int>(n + 1, -1));
        // return solve(word1,word2, 0, 0, dp);
        return tabulation(word1, word2);
    }
};