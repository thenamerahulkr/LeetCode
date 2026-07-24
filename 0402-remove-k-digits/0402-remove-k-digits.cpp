class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        deque<char> dq;
        // if(k == n) return "0";
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = num[i];
            while (!dq.empty() and dq.back() > ch and k > 0) {
                dq.pop_back();
                k--;
            }
            if (dq.size() == 0 and ch == '0') continue;
            dq.push_back(ch);
        }
        while (!dq.empty() && k > 0) {
            dq.pop_back();
            k--;
        }
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        // reverse(ans.begin(), ans.end());
        if(ans.length() == 0) return "0";
        return ans;
    }
};