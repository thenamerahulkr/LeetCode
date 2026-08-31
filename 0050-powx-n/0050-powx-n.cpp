class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 1)
            return double(x);
        if (n == 0)
            return double(1);
        if (n < 0)
            return myPow(1/x, -n);
        if (n % 2 == 0)
            return myPow(x * x, n / 2);

        return x * myPow(x * x, (n - 1) / 2);
    }
};