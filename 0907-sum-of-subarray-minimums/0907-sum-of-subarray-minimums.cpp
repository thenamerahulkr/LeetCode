// class Solution {
//     static const int MOD = 1e9 + 7;
// public:
//     int getMinInRange(vector<int>& arr, int i, int j) {
//         int currentMin = arr[i];
//         for (int k = i + 1; k <= j; k++) {
//             currentMin = min(currentMin, arr[k]);
//         }
//         return currentMin;
//     }

//     int sumSubarrayMins(vector<int>& arr) {
//         long long totalSum = 0;
//         int n = arr.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 int minVal = getMinInRange(arr, i, j);
//                 totalSum = (totalSum + minVal) % MOD;
//             }
//         }
//         return totalSum;
//     }
// };

class Solution {
    static const int MOD = 1e9 + 7;

private:
    vector<int> nsl(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // Use < to find strictly smaller elements
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> nsr(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Use <= to prevent double-counting duplicate elements
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        long long totalSum = 0;
        int n = arr.size();
        vector<int> nsleft = nsl(arr);
        vector<int> nsright = nsr(arr);
        for (int i = 0; i < n; i++) {
            long long left_count = i - nsleft[i];
            long long right_count = nsright[i] - i;
            long long total_ways = left_count * right_count;
            long long current_sum = (total_ways * arr[i]) % MOD;
            totalSum = (totalSum + current_sum) % MOD;
        }
        return totalSum % MOD;
    }
};