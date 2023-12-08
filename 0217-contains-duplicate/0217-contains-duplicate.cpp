class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag=false;
        sort(nums.begin(),nums.end());
        for(int i =1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                flag=true;
            }
        }
        return flag;
    }
};
// brute force solution 
// bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] == nums[j])
//                     return true;
//             }
//         }
//         return false;
//     }