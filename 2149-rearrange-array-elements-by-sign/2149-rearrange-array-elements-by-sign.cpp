class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);
        for (int k = 0; k < n; k++) {
            if(nums[k] < 0){
                ans[neg] = nums[k];
                neg += 2;
            }
            else{
                ans[pos] = nums[k];
                pos += 2;
            }
        }
        return ans;
    }
};