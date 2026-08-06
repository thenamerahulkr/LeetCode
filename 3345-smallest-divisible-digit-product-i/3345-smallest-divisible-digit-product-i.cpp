class Solution {
public:
    int prod_g(int n) {
        int prod = 1;
        while (n > 0) {
            int last_digit = n % 10;
            prod *= last_digit;
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int x = n;
        int prod = prod_g(n);
        if (prod % t == 0) return x;
           
        for (int i = n + 1; i < n + 10; i++) {
            int prod = prod_g(i);
            if (prod % t == 0) return i; 
        }
        return 0;
    }
};