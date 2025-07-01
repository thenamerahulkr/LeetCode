class Solution {
public:
    int divisor(vector<int>& nums, int some_value) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + some_value - 1) / some_value;
        }
        return sum;
    }
    int final_ans(vector<int>& nums, int threshold) {
        int n = nums.size();
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int total = divisor(nums, mid);
            if (total <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        return final_ans(nums,threshold);
    }
};