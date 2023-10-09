class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // left index
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start) / 2;
        int left = -1;

        while(start <= end) {
            if(nums[mid] == target) {
                left = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
            mid = start + (end - start) / 2; 
        }

        if(left == -1) return {-1, -1};


        // right index
        start = 0;
        end = nums.size()-1;
        mid = start + (end - start) / 2;
        int right = -1;

        while(start <= end) {
            if(nums[mid] == target) {
                right = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
            mid = start + (end - start) / 2;
        }

        return {left, right};
    }
};