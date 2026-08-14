class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;
                
                // If frequency exceeds 2, no valid substring can start at 'i' and extend past 'j'
                if (freq[s[j] - 'a'] > 2) {
                    break;
                }
                
                max_len = max(max_len, j - i + 1);
            }
        }

        return max_len;
    }
};