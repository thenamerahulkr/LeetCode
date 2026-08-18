class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Case 1: Subarray size is 1
        if (k == 1) {
            int ans = -1;
            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = std::max(ans, num);
                }
            }
            return ans;
        }

        // Case 2: Subarray size equals array length
        if (k == n) {
            int ans = -1;
            for (int num : nums) {
                ans = std::max(ans, num);
            }
            return ans;
        }

        // Case 3: 1 < k < n
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }

        return ans;
    }
};