class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> numSet(arr.begin(),arr.end()); 
        int missingCount = 0;
        int num = 1; 
        while (true) {
            if (numSet.find(num) == numSet.end()) { 
                missingCount++;
                if (missingCount == k)
                    return num; 
            }
            num++;
        }
    }
};