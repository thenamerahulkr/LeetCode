class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int x = 0; 
        for (int i = 0; i < size; i++) {
            x = x^nums[i];
        }
        return x;
    }
};