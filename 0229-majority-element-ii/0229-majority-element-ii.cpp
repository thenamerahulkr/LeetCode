class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency of each number
        for(int num : nums){
            freq[num]++;
        }
        
        vector<int> result;
        
        // Step 2: Check if frequency > n/3
        for(auto it : freq){
            if(it.second > n/3){
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};
