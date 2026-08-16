class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        long long right_sum = 0;

        // Iterate from right to left
        for (int i = n - 1; i >= 0; --i) {
            int elements_to_right = n - 1 - i;
            
            // The rightmost element is never dominant (elements_to_right == 0)
            if (elements_to_right > 0) {
                if ((long long)nums[i] * elements_to_right > right_sum) {
                    count++;
                }
            }
            
            right_sum += nums[i];
        }

        return count;
    }
};