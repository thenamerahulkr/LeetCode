class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int n = s.length();
        int left = 0, right = 0;
        int max_len = 0;
        while(right < n){
            freq[s[right]]++;
            while(freq[s[right]] > 2){
                freq[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};