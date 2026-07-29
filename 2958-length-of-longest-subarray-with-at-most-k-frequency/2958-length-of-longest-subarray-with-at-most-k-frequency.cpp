class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // <= k
        int n = nums.size();
        // map lenge jo freq store krega
        unordered_map<int, int> mp;
        int left = 0;
        int right = 0;
        int max_len = 0;
        while (right < n) {
            mp[nums[right]]++;
            while (mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};