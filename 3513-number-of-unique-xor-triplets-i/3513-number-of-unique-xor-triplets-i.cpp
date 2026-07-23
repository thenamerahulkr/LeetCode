class Solution {
private:
    int nextGreaterPowerOfTwo(int n) {
        int power = 1;
        while (power <= n) {
            power *= 2;
        }
        return power;
    }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // unordered_set<int> uniqueXors;

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         for (int k = j; k < n; k++) {
        //             int xorValue = nums[i] ^ nums[j] ^ nums[k];
        //             uniqueXors.insert(xorValue);
        //         }
        //     }
        // }

        // return uniqueXors.size();
        if(n == 1 or n == 2) return n;
        else return nextGreaterPowerOfTwo(n);
    }
};