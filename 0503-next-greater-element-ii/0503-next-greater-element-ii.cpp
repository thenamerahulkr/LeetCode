class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
           bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    ans[i] = nums[j];
                    found = true;
                    break;
                }
            }
            if (!found) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[i]) {
                        ans[i] = nums[j];
                        found = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};