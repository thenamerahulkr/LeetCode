class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long max_sum = 0;
        long long currSum = 0;
        while (right < k) {
            currSum += nums[right];
            freq[nums[right]]++;
            right++;
        }
        if (freq.size() == k) {
            max_sum = currSum;
        }
        while (right < n) {
            currSum += nums[right];
            freq[nums[right]]++;
            right++;
            currSum -= nums[left];
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
            if (freq.size() == k) {
                max_sum = max(max_sum, currSum);
            }
        }
        return max_sum;
    }
};