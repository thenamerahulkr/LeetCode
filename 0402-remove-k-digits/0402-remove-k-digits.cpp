class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        // if(k == n) return "0";
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = num[i];
            while (!st.empty() and st.top() > ch and k > 0) {
                st.pop();
                k--;
            }
            if (st.size() == 0 and ch == '0') continue;
            st.push(ch);
        }
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans.length() == 0) return "0";
        return ans;
    }
};