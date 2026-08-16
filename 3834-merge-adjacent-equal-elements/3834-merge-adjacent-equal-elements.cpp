class Solution {
    using LL = long long;

public:
    vector<LL> mergeAdjacent(vector<int>& nums) {
        vector<LL> res;
        for (int x : nums) {
            res.push_back(x);
            while (res.size() >= 2 && res.back() == res[res.size() - 2]) {
                LL val = res.back();
                res.pop_back();
                res.back() += val;
            }
        }
        return res;
    }
};