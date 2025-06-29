class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_length = 0, zeroes = 0, left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right] == 0) zeroes++;
            // if zero exceeds then // shrink wala chiz happen
            while(zeroes > k){
                if(nums[left] == 0) zeroes--;
                left++;
            }
            // the zeroes is under control of k 
            if(zeroes <= k){
                max_length = max(max_length,right - left + 1);
            }
            right ++;
        }
        return max_length;
    }
};