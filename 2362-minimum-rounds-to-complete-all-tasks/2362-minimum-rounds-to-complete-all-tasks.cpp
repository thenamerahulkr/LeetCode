class Solution {
public:
    int minimumRounds(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto [key, value] : mp){
            if(value == 1){
                return -1;
            }
            int rem = value % 3;
            if( rem == 0){
                ans += (value / 3);
            }
            else if( rem == 1){
                ans += 2 + (value - 4)/3;
            }
            else if(rem == 2){
                ans += 1 + (value - 2)/3;
            }
        }
        return ans;
    }
};