class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            if (ch == '(') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
    void solve(vector<string>& ans, string& temp, int n, int countClose,
               int countOpen) {
        // base case
        if (temp.size() == 2 * n) {
            if (isValid(temp)) {
                ans.push_back(temp);
            }
            return;
        }
        if (countOpen < n) {
            temp.push_back('(');
            solve(ans, temp, n, countClose, countOpen + 1);
            temp.pop_back();
        }

        if (countClose < countOpen) {
            temp.push_back(')');
            solve(ans, temp, n, countClose + 1, countOpen);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        int countOpen = 0;
        int countClose = 0;
        solve(ans, temp, n, countOpen, countClose);
        return ans;
    }
};