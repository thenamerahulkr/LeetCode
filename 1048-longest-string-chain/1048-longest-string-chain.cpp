class Solution {
public:
    bool canTake(string& s1, string& s2) {
        // s1 > s2 hoga always
        int m = s1.length();
        int n = s2.length();
        if (m != n + 1) return false;
        int diff = 0;
        int i = 0, j = 0;
        while (i < m and j < n) {
            if (s1[i] == s2[j]) {
                i++, j++;
            } else if (s1[i] != s2[j]) {
                diff++;
                i++;
            }
        }
        return diff <= 1;
    }
    int doubleLoop(vector<string>& nums) {
        // O(n^2);
        int n = nums.size();
        vector<int> lis(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (canTake(nums[i], nums[j])) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        return doubleLoop(words);
    }
};