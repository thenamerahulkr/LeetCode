class Solution {
private:
    bool kya_kar_payega(vector<int>& time, int totalTrips, long long given_time) {
        long long number_of_trips = 0;
        for (int i = 0; i < time.size(); i++) {
            number_of_trips += (long long)given_time / time[i];
            if (number_of_trips >= totalTrips)
                return true;
        }
        return false;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long high_value = *max_element(time.begin(), time.end());
        long long high = high_value * (long long)totalTrips;

        long long low = 1;
        long long answer = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (kya_kar_payega(time, totalTrips, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};