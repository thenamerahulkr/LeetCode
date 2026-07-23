class Solution {
private:
    // Approach 1: Brute Force
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    vector<int> bruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            bool found = false;

            // Current element ke right side mein search
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    ans[i] = nums[j];
                    found = true;
                    break;
                }
            }

            // Right side mein nahi mila, toh beginning se search
            if (!found) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[i]) {
                        ans[i] = nums[j];
                        break;
                    }
                }
            }
        }

        return ans;
    }

    // Approach 2: Optimal - Monotonic Stack
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    vector<int> optimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int index = i % n;

            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            if (i < n && !st.empty()) {
                ans[index] = st.top();
            }

            st.push(nums[index]);
        }

        return ans;
    }

public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Brute-force approach test karne ke liye:
        // return bruteForce(nums);

        // Final optimal approach:
        return optimal(nums);
    }
};