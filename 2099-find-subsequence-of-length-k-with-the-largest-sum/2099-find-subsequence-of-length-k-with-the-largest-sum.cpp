class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push({nums[i], i});
        }
        vector<pair<int, int>> selected;
        for (int i = 0; i < k; ++i) {
            selected.push_back(maxHeap.top());
            maxHeap.pop();
        }
        auto lambda = [](auto& a, auto& b){
            return a.second < b.second;
        };
        sort(selected.begin(), selected.end(),lambda);
        vector<int> result;
        for (auto& p : selected) {
            result.push_back(p.first);
        }
        return result;
    }
};