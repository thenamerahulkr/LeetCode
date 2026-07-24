class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> dq;

        for (char c : s) {
            if (!dq.empty() && dq.back() == c) {
                dq.pop_back();
            } else {
                dq.push_back(c);
            }
        }
        string res = "";
        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
        }

        return res;
    }
};