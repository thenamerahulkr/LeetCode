class Solution {
public:
    bool isPossibleCandies(vector<int>& candies, long long k, long long mid) {
        int n = candies.size();
        long long maxNumberOfChildren = 0;
        for (int i = 0; i < n; i++) {
            maxNumberOfChildren += candies[i] / mid;
        }
        return maxNumberOfChildren >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int max_candies = 0;
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleCandies(candies, k, mid)) {
                max_candies = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return max_candies;
    }
};