class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sumLeft = 0, sumRight = accumulate(nums.begin(), nums.end(), 0);
        int res = 0;
        for(int i = 0; i < (int)nums.size() - 1; ++i){
            sumLeft += nums[i];
            sumRight -= nums[i];
            if(!(abs(sumLeft - sumRight) & 1)){
                ++res;
            }
        }
        return res;
    }
};