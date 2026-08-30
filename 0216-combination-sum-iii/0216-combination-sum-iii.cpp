class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans, int k) {
        if(k < 0) return;
        if (target == 0 and k == 0) {
            ans.push_back(temp);
            return;
        }

        if (index == candidates.size() || target < 0) {
            return;
        }

        // Take
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);

            // index + 1 because element can be used only once
            solve(index + 1, candidates, target - candidates[index], temp, ans, k-1);

            temp.pop_back();
        }
        solve(index + 1, candidates, target, temp, ans, k);
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans, k);

        return ans;
    }
};