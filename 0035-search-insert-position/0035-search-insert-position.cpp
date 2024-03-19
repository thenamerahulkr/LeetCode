class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=nums.size();
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=target){
                ans=i;
                break;
            }
        }
        return ans;
    }
};