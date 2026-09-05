class Solution {
public:
    int lisLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> lis(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (lis[j] + 1 > lis[i]) {
                        lis[i] = lis[j] + 1;
                        count[i] = count[j]; // Reset count for the new longer
                                             // subsequence length
                    } else if (lis[j] + 1 == lis[i]) {
                        count[i] +=
                            count[j]; // Accumulate count for same length LIS
                    }
                }
            }
        }

        int maxLength = *max_element(lis.begin(), lis.end());
        int totalCount = 0;

        for (int i = 0; i < n; i++) {
            if (lis[i] == maxLength) {
                totalCount += count[i];
            }
        }

        return totalCount;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lisLength(nums);
    }
};