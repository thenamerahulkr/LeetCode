class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mp;
        for (int i : banned) {
            mp[i]++;
        }
        int sum = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp[i]) {
                sum += i;
                if (sum <= maxSum) {
                    res++;
                } else {
                    return res; 
                }
            }
        }
        return res;
    }
};