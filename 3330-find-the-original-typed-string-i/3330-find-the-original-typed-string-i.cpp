class Solution {
public:
    int possibleStringCount(string s) {
        int n = s.length();
        int count = 1;
        for (int i = 1; i < n; i++) {
           if(s[i-1] == s[i]) count++;
        }
        return count;
    }
};