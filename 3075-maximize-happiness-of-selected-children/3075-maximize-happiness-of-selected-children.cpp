class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        long long max_happinies = INT_MIN;
        sort(happiness.begin(), happiness.end());
        int counter = 0;
        long long sum = 0;
        for (int i = n - 1; i >= 0, k > 0; i--) {
            sum += happiness[i] - counter;
            counter++;
            k--;
            max_happinies = max(sum, max_happinies);
        }
        return max_happinies;
    }
};