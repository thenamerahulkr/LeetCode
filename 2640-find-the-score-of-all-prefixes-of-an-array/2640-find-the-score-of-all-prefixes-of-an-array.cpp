class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        // vector<long long> conversion(nums.size());
        vector<long long> ans(nums.size());
        int mx=nums[0];
        ans[0]=2*nums[0];
        // score[0]=conversion[0];
        for(int i=1;i<nums.size();i++){
            if(mx<nums[i]){
                mx=nums[i];
            }
            ans[i]=nums[i]+mx;
            ans[i]=ans[i]+ans[i-1];
        }
        return ans;
    }
};