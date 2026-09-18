class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // number,index;
        unordered_map<int, int> mp;
        // mp[0] = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp[target- nums[i]], i};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};