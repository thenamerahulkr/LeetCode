class Solution {
private:
    void makeCombination(vector<int>& arr, int target, int idx, vector<int>& ds, int total, vector<vector<int>>& res) {
        int n = arr.size();
        if(total == target) {
            res.push_back(ds);
            return;
        }
        if(idx > n and target != total) return;
        if(total > target || idx >= arr.size()) {
            return;
        }
        ds.push_back(arr[idx]);
        makeCombination(arr, target, idx, ds, total + arr[idx], res);
        ds.pop_back();
        makeCombination(arr, target, idx + 1, ds, total, res);
    }   
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        makeCombination(arr, target, 0, ds, 0, res);
        return res;    
    }
};