class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] %2 ==0) nums[i] = 0;
            else nums[i] = 1;
        }
        unordered_map <int, int> mp;
        mp[0] = 1;
        int current_sum = 0;
        for(int i = 0; i < n; i++){
            // sum and how many that sum is seen
            current_sum += nums[i];
            int  check =  current_sum - k;
            // check into map 
            if(mp.find(check) != mp.end()){
                result += mp[check];
            }
            mp[current_sum]++;
        }
        return result;
    }
};