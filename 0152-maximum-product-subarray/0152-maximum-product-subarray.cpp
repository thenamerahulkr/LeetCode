class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = i; j < n; j++){
                prod *= nums[j];
                max_prod = max(max_prod, prod);
            }
        }
        return max_prod;
    }
};