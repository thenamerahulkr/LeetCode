class Solution {
public:
    // int solveWithMemo(int i, int j, string& s) {
    //     if (i >= j)
    //         return 0;

    //     if (s[i] == s[j]) {
    //         return 0 + solveWithMemo(i + 1, j - 1, s);
    //     } else {
    //         return 1 +
    //                min(solveWithMemo(i + 1, j, s), solveWithMemo(i, j - 1, s));
    //     }
    // }
    int memo[1000][1000];
    int solveWithMemo(int i, int j, string& s) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (s[i] == s[j]) {
            return memo[i][j] = 2 + solveWithMemo(i + 1, j - 1, s);
        } else {
            return memo[i][j] = max(solveWithMemo(i + 1, j, s),
                                    solveWithMemo(i, j - 1, s));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memset(memo, -1, sizeof(memo));
        return solveWithMemo(0, n - 1, s);
    }
    int minInsertions(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveWithMemo(0, n - 1, s);
        return n - longestPalindromeSubseq(s);
    }
};