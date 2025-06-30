class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_len = 0;
        unordered_map<int,int>freq;
        for(auto& x: nums){
            freq[x]++;
        }
        for(auto& [number , count]: freq){
            if(freq.count(number+1)){
                max_len = max(max_len, count + freq[number+1]);
            }
        }
        return max_len;
    }
};