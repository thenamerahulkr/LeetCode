class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        if (rightSum % 2 != 0) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];  
            rightSum -= nums[i]; 
            if (abs(leftSum - rightSum) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};
