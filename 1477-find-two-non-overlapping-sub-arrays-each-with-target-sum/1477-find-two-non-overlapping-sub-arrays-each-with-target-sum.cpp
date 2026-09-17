class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, 1e6);
        int currSum = 0, left = 0, right = 0;
        int ans = 1e6, bestSoFar = 1e6;
        while (right < n) {
            currSum += arr[right];
            while (left < right && currSum > target) {
                currSum -= arr[left];
                left++;
            }
            if (currSum == target) {
                int curr_len = right - left + 1;
                if (left > 0 && min_len[left - 1] != 1e6) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                bestSoFar = min(bestSoFar, curr_len);
            }
            min_len[right] = bestSoFar;
            right++;
        }
        return ans == 1e6 ? -1 : ans;
    }
};