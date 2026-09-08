class Solution {
private:
    int memo[1000][1000];
    int solveWithMemo(int i, int j, string& s) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) {
            return memo[i][j] = 2 + solveWithMemo(i + 1, j - 1, s);
        } else {
            return memo[i][j] = max(solveWithMemo(i + 1, j, s), solveWithMemo(i, j - 1, s));
        }
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memset(memo, -1, sizeof(memo));
        return solveWithMemo(0, n - 1, s);
    }
};