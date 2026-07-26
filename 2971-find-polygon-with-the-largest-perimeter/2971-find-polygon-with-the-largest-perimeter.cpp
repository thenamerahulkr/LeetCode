class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // c < a + b
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long perimeter = -1;
        long long cumm = nums[0] + nums[1];
        for(int i = 2; i < n; i++){
            if(nums[i] >= cumm) cumm = cumm + nums[i];
            else{
                cumm += nums[i];
                perimeter = max(cumm, perimeter);
            }
        }

        return perimeter;
    }
};