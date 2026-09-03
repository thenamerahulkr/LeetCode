class Solution {
public:
    long long solveWithMemo(vector<vector<int>>& questions, int i,
                            vector<long long>& dp) {
        int n = questions.size();
        // base case
        if (i >= n)
            return 0;
        // if(i == n-1) return questions[i][0];
        // we can take or skip present index
        if (dp[i] != -1)
            return dp[i];
        long long choose =
            questions[i][0] +
            solveWithMemo(questions, i + questions[i][1] + 1, dp);
        long long ignore = solveWithMemo(questions, i + 1, dp);
        return dp[i] = max(choose, ignore);
    }
    long long solveWithTabulation(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int nextIndex = i + questions[i][1] + 1;
            long long choose = questions[i][0] + (nextIndex <= n ? dp[nextIndex] : 0); 
            long long ignore = dp[i+1];
            dp[i] = max(choose, ignore);
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        // we have two options and choose or skip
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        // return solveWithMemo(questions, 0, dp);
        return solveWithTabulation(questions);
    }
};