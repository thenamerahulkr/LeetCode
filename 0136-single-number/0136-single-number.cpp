class Solution {
public:
    int singleNumber(vector<int>& nums) { 
    // Size of the array:
    int n = nums.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = nums[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (nums[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
    }
};