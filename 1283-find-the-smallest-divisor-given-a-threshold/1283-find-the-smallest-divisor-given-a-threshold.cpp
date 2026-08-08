class Solution {
public:

    bool possible(vector<int>& nums, int divisor, int threshold) {

        long long sum = 0;

        for (int x : nums) {

            sum += ceil((double)x / divisor);
            if (sum > threshold)
                return false;
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(nums, mid, threshold)) {

                ans = mid;
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};