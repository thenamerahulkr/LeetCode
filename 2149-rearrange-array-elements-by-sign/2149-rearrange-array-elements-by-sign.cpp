class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,0);
        int posivite_ptr = 0;
        int negative_ptr = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                arr[posivite_ptr] = nums[i];
                posivite_ptr += 2;
            }
            else{
                arr[negative_ptr] = nums[i];
                negative_ptr += 2;
            }
        }
        return arr;
    }
};