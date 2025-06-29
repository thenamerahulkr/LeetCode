class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                count = 0;
            }
            max_len = max(count,max_len);
        }
        return max_len;
    }
};