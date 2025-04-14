class Solution {
private:
    int solve(vector<int>& nums, int index){
        // base case 
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0],nums[1]);
        if(index < 0)  return 0;
        // take 
        int loot = nums[index] + solve(nums,index-2);
        // not take
        int not_loot = 0 + solve(nums, index-1);
        return max(not_loot,loot);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n-1);
    }
};