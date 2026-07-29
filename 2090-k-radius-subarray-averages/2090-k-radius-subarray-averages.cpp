class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        vector<int> answer(n, -1);
        if (n < 2 * k + 1) return answer;
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        // prefix [i] = pre[i-1] + pre[i];
        for(int i = 1; i < n ; i++){
            prefix[i] = prefix[i-1] + (long long)nums[i];
        }
        for(int i = k; i < n - k; i++){
            long long leftSum = (i - k > 0) ? prefix[i - k - 1] : 0;
            long long currentSubarraySum = prefix[i + k] - leftSum;
            answer[i] = currentSubarraySum / (2 * k + 1);
        }
        return answer;
    }
};