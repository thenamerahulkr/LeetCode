class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0; 
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                // reverse [start, i-1]
                int l = start, r = i - 1;
                while (l < r) {
                    swap(s[l], s[r]);
                    ++l; --r;
                }
                start = i + 1; // move to the next word
            }
        }
        return s;
    }
};
