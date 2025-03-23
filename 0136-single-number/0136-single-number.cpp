class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        }
        for(auto e:mp){
            if(e.second==1)
            return e.first;
        }
        return -1;
    }
};