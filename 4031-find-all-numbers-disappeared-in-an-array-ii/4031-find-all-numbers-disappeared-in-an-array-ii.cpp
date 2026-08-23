class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> ans;
        unordered_set<int> st(nums.begin(), nums.end()); // -> O(n);
        int low = -1;
        bool flag = false;

        for (int x = lower; x <= upper; x++) { // O(upper - lowe + 1);
            // x missing hai
            if (!st.count(x) && !flag) {
                low = x;
                flag = true;
            }
            // x present hai -> missing range close karo
            else if (st.count(x) && flag) {
                vector<int> temp = {low, x - 1};
                ans.push_back(temp);
                flag = false;
            }
        }
        if (flag) {
            vector<int> temp = {low, upper};
            ans.push_back(temp);
        }
        return ans;
    }
};