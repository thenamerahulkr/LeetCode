class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long firstMax = nums.back();
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;
        
        bool foundSecond = false;
        bool foundThird = false;
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] == firstMax) {
                continue;
            }
            if (!foundSecond) {
                secondMax = nums[i];
                foundSecond = true;
                continue;
            }
            if (nums[i] == secondMax) {
                continue;
            }
            if (!foundThird) {
                thirdMax = nums[i];
                foundThird = true;
                break;
            }
        }
        
        return foundThird ? thirdMax : firstMax;
    }
};