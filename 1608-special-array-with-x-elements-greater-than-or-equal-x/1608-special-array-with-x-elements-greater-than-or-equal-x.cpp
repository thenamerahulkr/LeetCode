class Solution {
private:
    int bs(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first_idx = n;
        while(low <= high){
            int mid = high - low / 2;
            if(nums[mid] >= x){
                first_idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // count of that element greater than equal to x
        return n - first_idx;
    }
public:
    int specialArray(vector<int>& nums) {
        // isko binary search se kro  ab 
        // array sort kro pehle
        int n = nums.size();
        sort(nums.begin(),nums.end()); // n longn
        for (int i = 0; i <= n; i++) { // n
            // int count = 0;
            //  for (int num : nums) {
            //     if (num >= i) {
            //         count++;
            //     }
            // }
            int count = bs(nums,i); // log(i);
            
            if (count == i) return i;
        }
        
        return -1;
    }
};