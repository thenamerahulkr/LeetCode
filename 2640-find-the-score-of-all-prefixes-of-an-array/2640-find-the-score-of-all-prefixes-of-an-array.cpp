class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conversion(nums.size());
        vector<long long> score(nums.size());
        int mx=nums[0];
        conversion[0]=2*nums[0];
        score[0]=conversion[0];
        for(int i=1;i<nums.size();i++){
            if(mx<nums[i]){
                mx=nums[i];
            }
            conversion[i]=nums[i]+mx;
            score[i]=conversion[i]+score[i-1];
        }
        return score;
    }
};