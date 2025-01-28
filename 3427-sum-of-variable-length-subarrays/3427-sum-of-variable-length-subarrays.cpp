class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int s, ans = 0;

        for(int i=0;i<n;i++){
            s = max(0,i-nums[i]);
            for(int j=s;j<=i;j++){
                ans+=nums[j];
            }
        }

        return ans;
    }
};