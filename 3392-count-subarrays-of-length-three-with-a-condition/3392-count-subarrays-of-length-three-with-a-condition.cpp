class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size()-2; i++){
            if(2*(nums[i]+nums[i+2]) == nums[i+1]){
                count++;
            }
        }
        return count;
    }
};