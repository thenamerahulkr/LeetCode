class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_map<char, int> last_seen_at;
        int last_index[26] = {0};
        bool seen[26] = {false};
        stack<char> st;
        string result = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            // last_index[s[i] - 'a'] = i;
            last_seen_at[ch - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (seen[ch - 'a'])
                continue;
            else {
                while (!st.empty() && st.top() > ch &&
                       last_seen_at[st.top() - 'a'] > i) {
                    seen[st.top() - 'a'] = false;
                    st.pop();
                }
            }
            st.push(ch);
            seen[ch - 'a'] = true;
        }
        while (st.size() != 0) {
            result = result + st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};