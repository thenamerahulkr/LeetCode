class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int left = 0, right = n - 1;
        
        res[left++] = nums[0];
        res[right--] = nums[1];
        
        int last1 = nums[0];
        int last2 = nums[1];
        
        for (int i = 2; i < n; ++i) {
            if (last1 > last2) {
                res[left++] = nums[i];
                last1 = nums[i];
            } else {
                res[right--] = nums[i];
                last2 = nums[i];
            }
        }
        reverse(res.begin() + left, res.end());
        
        return res;
    }
};