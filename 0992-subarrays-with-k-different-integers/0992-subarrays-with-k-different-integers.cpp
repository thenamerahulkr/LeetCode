class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int right = 0; right < n; right++) {
            mp[nums[right]]++;
            while (mp.size() > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};