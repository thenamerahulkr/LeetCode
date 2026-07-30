class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // maximum len of subarray with dis element;
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int max_sum = 0;
        int curr_sum = 0;
        while(right < n){
            curr_sum = curr_sum + nums[right];
            mp[nums[right]]++;
            while (mp[nums[right]] > 1) {
                curr_sum -= nums[left];
                mp[nums[left]]--;
                left++;
            }
            max_sum = max(max_sum, curr_sum);
            right++;
        }
        return max_sum;
    }
};