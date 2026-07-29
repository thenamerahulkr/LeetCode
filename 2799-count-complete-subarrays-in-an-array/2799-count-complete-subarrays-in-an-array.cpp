class Solution {
unordered_map<int, int> mp;
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int wholeDistinct = st.size(); // yhi mera k ho gya 
        // ab tm ye find kro ki kitne subarray hai jiski element ki freq distinct  = k hai bss yhi nikal hai 
        int count = 0;
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n){
            mp[nums[right]]++;
            // count = n - right + 1;'
            while(mp.size() == wholeDistinct){
                count += (n - right);
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            
            right++;
        } 
        return count;
    }
};