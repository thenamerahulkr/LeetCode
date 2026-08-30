class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index == candidates.size() || target < 0) {
            return;
        }

        // Option 1: Include the current element (can be reused, so index
        // doesn't increment)
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            solve(index, candidates, target - candidates[index], temp, ans);
            temp.pop_back(); // backtrack
        }

        // Option 2: Exclude the current element and move to the next index
        solve(index + 1, candidates, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};