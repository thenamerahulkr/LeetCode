class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        ll answer = 0;
        ll current_sum = 0;
        int left = 0;
        int right = 0;
        while(right < n){
            current_sum += nums[right];
            while(left <= right and current_sum*(right-left+1) >=k){
                current_sum -= nums[left];
                left++;
            }
            answer += right-left+1;
            right++;
        }
        return answer;
    }
};