class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int count = 0;
        
        // First pass: Elements less than pivot
        for (int num : nums) {
            if (num < pivot) {
                ans[count] = num;
                count++;
            }
        }

        // Second pass: Elements equal to pivot
        for (int num : nums) {
            if (num == pivot) {
                ans[count] = num;
                count++;
            }
        }

        // Third pass: Elements greater than pivot
        for (int num : nums) {
            if (num > pivot) {
                ans[count] = num;
                count++;
            }
        }

        return ans;
    }
};