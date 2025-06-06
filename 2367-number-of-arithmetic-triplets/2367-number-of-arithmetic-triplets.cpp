class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] - nums[i] == diff and
                        nums[k] - nums[j] == diff) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};