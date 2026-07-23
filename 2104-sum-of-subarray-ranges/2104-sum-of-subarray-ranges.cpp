class Solution {
private:
    // Next Greater Element on Right
    vector<int> ngr(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return right;
    }

    // Next Greater Element on Left
    vector<int> ngl(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return left;
    }

    // Next Smaller Element on Left
    vector<int> nsl(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return left;
    }

    // Next Smaller Element on Right
    vector<int> nsr(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return right;
    }

    // Sum of minimum values of all subarrays
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;

        vector<int> nsleft = nsl(arr);
        vector<int> nsright = nsr(arr);

        for (int i = 0; i < n; i++) {
            long long leftCount = i - nsleft[i];
            long long rightCount = nsright[i] - i;

            long long totalWays = leftCount * rightCount;
            long long currentSum = totalWays * arr[i];

            totalSum += currentSum;
        }

        return totalSum;
    }

    // Sum of maximum values of all subarrays
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;

        vector<int> ngleft = ngl(arr);
        vector<int> ngright = ngr(arr);

        for (int i = 0; i < n; i++) {
            long long leftCount = i - ngleft[i];
            long long rightCount = ngright[i] - i;

            long long totalWays = leftCount * rightCount;
            long long currentSum = totalWays * arr[i];

            totalSum += currentSum;
        }

        return totalSum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};