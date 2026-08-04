class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = mini; i <= maxi; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};