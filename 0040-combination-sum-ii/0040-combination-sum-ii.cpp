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

        // Take
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);

            // index + 1 because element can be used only once
            solve(index + 1, candidates, target - candidates[index],
                  temp, ans);

            temp.pop_back();
        }

        // Skip duplicates while NOT taking current element
        int next = index + 1;
        while (next < candidates.size() &&
               candidates[next] == candidates[index]) {
            next++;
        }

        // Not take
        solve(next, candidates, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};