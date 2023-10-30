class Solution {
public:
    int missingNumber(vector<int>& nums) {
         // Outer loop that runs from 1 to N:
    int N=nums.size();
    for (int i = 0; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;
        //Search the element using linear search:
        for (int j = 0; j <=N - 1; j++) {
            if (nums[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
       // method -2         
         // int n=nums.size();
        // int totalSum=(n*(n+1))/2;
        // long sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum=sum+nums[i];
        // }
        // return totalSum - sum;
    }
    
};