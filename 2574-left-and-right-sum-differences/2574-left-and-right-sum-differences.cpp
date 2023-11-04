class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> leftSum(nums.size());
        vector<int> rightSum(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            // leftSum.push_back(sum);
            leftSum[i]=sum;
            sum=sum+nums[i];
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            // rightSum.push_back(sum);
            rightSum[i]=sum;
            sum=sum+nums[i];
        }
        for(int i=0;i<ans.size();i++){
            int diff=abs(leftSum[i]-rightSum[i]);
            ans[i]=diff;
        }
        return ans;
    }
};