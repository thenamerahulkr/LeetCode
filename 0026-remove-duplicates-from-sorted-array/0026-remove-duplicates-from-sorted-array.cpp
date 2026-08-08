class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int j = 1;
        // unordered_set<int> st;
        // vector<int> ans;
        // for(int i = 0; i < nums.size(); i++){
        //     // if(nums[i] != nums[i - 1]){
        //     //     nums[j] = nums[i];
        //     //     j++;
        //     // }
        //     st.insert(nums[i]);
        // }
        // for(auto ele:st){
        //     ans.push_back(st.)
        // }
        // return j;
        int left = 1;
        for(int right = 1; right < nums.size(); right++){
            if(nums[right] != nums[left - 1]){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
        set<int> st(nums.begin(), nums.end());
        int i = 0;
        // int i = 0;
        for (int val : st) {
            nums[i++] = val;
        }
        return st.size();
    }
};