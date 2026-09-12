class Solution {
public:
    void computeLIS(vector<int>& nums, vector<int>& lis) {
        // O(n^2);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
    }
    void computeLDS(vector<int>& nums, vector<int>& lds) {
        // O(n^2);
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        computeLIS(nums, lis);
        computeLDS(nums, lds);
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxMountainLength = max(maxMountainLength, lis[i] + lds[i] - 1);
            }
        }
        return n - maxMountainLength;
    }
};