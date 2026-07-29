class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int max_len = 0;
        int left = 0, right = 0;
        int currCost = 0;
        while(right < n){
            currCost += abs(s[right] - t[right]);
            while(currCost > maxCost){
                currCost -= abs(s[left] - t[left]);
                left++;
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};