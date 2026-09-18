class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;
        
        for (int num : st) {
            // Check if this number is the start of a sequence
            if (!st.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Count consecutive numbers
                while (st.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                maxLen = max(maxLen, currentStreak);
            }
        }
        
        return maxLen;
    }
};


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0)
//             return 0;
//         sort(nums.begin(), nums.end());
//         int maxLen = 1;
//         int currLen = 1;
//         for (int i = 1; i < n; i++) {
//             if (nums[i] == nums[i - 1]) {
//                 continue;
//             }
//             if (nums[i] == nums[i - 1] + 1) {
//                 currLen++;
//             } else {
//                 currLen = 1;
//             }
//             maxLen = max(maxLen, currLen);
//         }
//         return maxLen;
//     }
// };