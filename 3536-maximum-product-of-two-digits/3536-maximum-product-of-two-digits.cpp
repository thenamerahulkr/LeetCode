class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        int len = str.length();
        sort(str.begin(), str.end());
        int ij = str[len - 1] - '0';
        int jk = str[len - 2] - '0';
        return ij * jk;
    }
};