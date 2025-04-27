class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;
        int current_sum = 0;
        for(int i = 0; i < n; i++){
            current_sum += nums[i];
            max_sum = max(current_sum,max_sum);
            if(current_sum < 0){
                current_sum = 0;
            }
            
        }
        return max_sum;
    }
};