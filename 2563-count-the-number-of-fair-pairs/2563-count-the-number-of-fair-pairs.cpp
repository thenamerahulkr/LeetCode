class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        /// find all the pairs and check in the range
        long long count = 0;
        // for(int i = 0; i < nums.size() - 1; i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         int sum = nums[i] + nums[j];
        //         if(sum >= lower and sum <= upper) count++;
        //     }
        // }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() ; i++) {
            // lower bound yha
            auto left =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);

            auto right =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            count += right - left;

            // upper
        }
        return count;
    }
};