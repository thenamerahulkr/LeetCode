class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long start = 1000;
        long long commas = 1;
        while (start <= n) {
            long long nextStart = start * 1000;
            long long end = min(n, nextStart - 1);
            
            // Numbers from start to end all have the same number of commas
            totalCommas += (end - start + 1) * commas;
            
            start = nextStart;
            commas++;
        }
        return totalCommas;
    }
};