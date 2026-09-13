class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto it : mp) {
            vector<int> indices = it.second;
            if (indices.size() == 3) {

                int d = indices[1] - indices[0];

                if (indices[2] - indices[1] == d) {
                    ans++;
                }
            }
        }
        return ans;
    }
};