class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //         brute force method
//         for(int i=0;i<nums.size();i++){
//             int count=1;
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]==nums[j]){
//                     count++;
//                 }
//             }
//             if(count>nums.size()/2)
//                 return nums[i];
                
//         }
//         return -1;
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};