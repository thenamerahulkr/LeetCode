class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        long long totalPairs = (long long)n *(n - 1) / 2;
        unordered_map<int, long long> freq;
        long long goodPairs = 0;
        for(int i = 0; i < n; i++){
           int key = i - nums[i];
           goodPairs += freq[key];
           freq[key]++;
        }
        return totalPairs - goodPairs;

    }
};