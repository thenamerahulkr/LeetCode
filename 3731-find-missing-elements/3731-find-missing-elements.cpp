class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_set<int> num_set(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = mini; i <= maxi; i++) {
            if (num_set.find(i) == num_set.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};