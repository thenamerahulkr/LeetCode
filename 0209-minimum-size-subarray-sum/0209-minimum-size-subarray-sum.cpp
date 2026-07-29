class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int sum_run = 0;
        while (right < n) {
            sum_run += nums[right];
            if (sum_run >= target) {
                while (sum_run >= target) {
                    min_len = min(min_len, right - left + 1);
                    sum_run -= nums[left];
                    left++;
                }
            }
            right++;
        }
        if(min_len == INT_MAX) return 0;
        return min_len;
    }
};