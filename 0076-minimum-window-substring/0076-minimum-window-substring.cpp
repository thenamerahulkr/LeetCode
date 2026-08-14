class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> mp;
        for (char& ch : t) {
            mp[ch]++;
        }
        int left = 0, right = 0, count = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < n) {
            char ch = s[right];
            if (mp.find(ch) != mp.end()) {
                if (mp[ch] > 0) {
                    count++;
                }
                mp[ch]--;
                // count++;
            }
            while (count == m) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char leftChar = s[left];
                if (mp.find(leftChar) != mp.end()) {
                    mp[leftChar]++;
                    if (mp[leftChar] > 0) {
                        count--;
                    }
                }
                left++;
            }
            right++;
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }
};