class Solution {
public:
    int minOperations(vector<int>& nums) {
        // number and uska freq;
        int minimum_operation = 0;
        map<int, int> mp;
        for(auto &it : nums) mp[it]++;
        for(auto &[k,v] : mp){
            if(v == 1) return -1;
            minimum_operation += (v + 2) / 3;
        }
        return minimum_operation;
    }
};