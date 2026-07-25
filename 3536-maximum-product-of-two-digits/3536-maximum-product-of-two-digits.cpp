class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        int len = str.length();
        int max_prod = INT_MIN;
        // sort(str.begin(), str.end());
        // int ij = str[len - 1] - '0';
        // int jk = str[len - 2] - '0';
        // return ij * jk;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len ; j++) {
                int digit1 = str[i] - '0';
                int digit2 = str[j] - '0';
                int product = digit1 * digit2;
                max_prod = max(max_prod, product);
            }
        }
        return max_prod;
    }
};