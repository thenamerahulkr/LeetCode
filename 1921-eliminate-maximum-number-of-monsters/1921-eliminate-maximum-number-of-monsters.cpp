class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = (double)dist[i] / speed[i];
        }
        int timer = 0;
        int count = 0;
        sort(time.begin(), time.end());
        for (int i = 0; i < n; i++) {
            if (time[i] <= timer) {
                break;
            }

            timer++;
            count++;
        }
        return count;
    }
};