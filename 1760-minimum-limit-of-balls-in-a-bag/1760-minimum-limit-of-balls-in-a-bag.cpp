class Solution {
public:
    bool possible(vector<int>& nums, int mid, int maxOperations) {
        long long ops = 0;
        for (int x : nums) {
            ops += (x - 1) / mid;
        }
        return ops <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = low;
        // sort(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // yha se binary search -> kya mid value bnana possible hai ya ni
            // with under max ops
            if (possible(nums, mid, maxOperations)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};