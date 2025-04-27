class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumMap;
        int current_sum = 0;
        int counter = 0;
        prefixSumMap[0] = 1;  
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];  
            if (prefixSumMap.find(current_sum - k) != prefixSumMap.end()) {
                counter += prefixSumMap[current_sum - k];
            }
            prefixSumMap[current_sum]++;
        }
        return counter;
    }
};