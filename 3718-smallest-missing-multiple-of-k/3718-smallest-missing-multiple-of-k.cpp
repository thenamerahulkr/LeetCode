class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        for (int i = 1; ; ++i) {
            int multiple = k * i;
            if (!st.count(multiple)) {
                return multiple;
            }
        }
        return -1;
    }
};