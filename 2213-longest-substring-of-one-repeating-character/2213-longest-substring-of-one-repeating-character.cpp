#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int maxLen = 0;
    int prefLen = 0;
    int suffLen = 0;
    char prefChar = 0;
    char suffChar = 0;
    int len = 0;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;

        // Base max length from children
        res.maxLen = max(left.maxLen, right.maxLen);

        // Check boundary merge
        if (left.suffChar == right.prefChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);
        }

        // Calculate prefix length
        res.prefLen = left.prefLen;
        if (left.prefLen == left.len && left.prefChar == right.prefChar) {
            res.prefLen += right.prefLen;
        }

        // Calculate suffix length
        res.suffLen = right.suffLen;
        if (right.suffLen == right.len && right.suffChar == left.suffChar) {
            res.suffLen += left.suffLen;
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMaxLen() const {
        return tree[1].maxLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> result(k);
        
        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            result[i] = st.getMaxLen();
        }
        
        return result;
    }
};