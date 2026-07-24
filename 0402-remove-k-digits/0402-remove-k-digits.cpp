class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = num[i];
            while (!ans.empty() and ans.back() > ch and k > 0) {
                ans.pop_back();
                k--;
            }
            if (ans.length() == 0 and ch == '0') continue;
            ans.push_back(ch);
        }
        while (!ans.empty() && k > 0) {
            ans.pop_back();
            k--;
        }

        return ans.empty() ? "0" : ans;
    }
};