class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            if (nums[right] == 0) {
                // Record the max length before the window breaks
                maxi = max(maxi, right - left);
                // Move the left pointer past the 0
                left = right + 1;
            }
        }
        
        // Final check in case the array ends with a sequence of 1s
        maxi = max(maxi, n - left);
        
        return maxi;
    }
};