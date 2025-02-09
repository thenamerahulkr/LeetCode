class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int , int> mp;
        for(int i=0; i<n; i++){
            int remaining = target-nums[i];
            if(mp.find(remaining) != mp.end()){
                ans.push_back(mp[remaining]);
                ans.push_back(i);
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};