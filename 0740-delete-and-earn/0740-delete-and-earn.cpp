class Solution {
public:
    int solveWithMemo(vector<int>& arr, int i, vector<int>& dp) {
        if (i >= arr.size()) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int currValue = arr[i];
        int currSum = arr[i];
        int index = i + 1;

        while (index < arr.size() && arr[index] == currValue) {
            currSum += arr[i];
            index++;
        }
        while (index < arr.size() && arr[index] == currValue + 1) {
            index++;
        }
        return dp[i] = max(currSum + solveWithMemo(arr, index, dp), solveWithMemo(arr, i + 1, dp));
    }
    int deleteAndEarn(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, -1);
        return solveWithMemo(arr, 0, dp);
    }
};