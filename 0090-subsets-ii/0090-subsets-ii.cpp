class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // TAKE
        temp.push_back(nums[index]);

        solve(index + 1, nums, temp, ans);

        temp.pop_back();

        // SKIP
        int next = index + 1;

        while (next < nums.size() &&
               nums[next] == nums[index]) {
            next++;
        }

        solve(next, nums, temp, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};