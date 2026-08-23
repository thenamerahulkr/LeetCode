class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int x = 1;
        vector<int> ans;
        int n = nums.size();
        for(int i = 1; i <= n; i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};