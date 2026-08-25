class Solution {
public:
    void solve(int i, int j, vector<char>& s) {
        // base case
        if (i == j or i > j)
            return;
        swap(s[i], s[j]);
        solve(i + 1, j - 1, s);
    }
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        solve(i, j, s);
    }
};

/* time complexity will be O(n) and we are visiting each element only once*/ 