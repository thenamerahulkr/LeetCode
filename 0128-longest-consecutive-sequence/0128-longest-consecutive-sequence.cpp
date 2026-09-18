// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0)
//             return 0;
//         unordered_set<int> st(nums.begin(), nums.end());
//         int maxLen = 1;
//         for (int i = 0; i < n; i++) {
//             int number = nums[i];
//             int currLen = 1;

//             // starting point
//             if (st.count(number + 1)) {
//                 while (st.count(number + 1)) {
//                     number++;
//                     currLen++;
//                 }
//             }
//             maxLen = max(maxLen, currLen);
//         }
//         return maxLen;
//     }
// };


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                currLen++;
            } else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};