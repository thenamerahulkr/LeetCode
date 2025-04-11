class Solution {
public:
    void solve(vector<vector<int>> &answer, int index, vector<int> &ds, vector<int> &nums){
        // base case 
        if(index == nums.size()){
            answer.push_back(ds);
            return;
        }
        // include 
        ds.push_back(nums[index]);
        solve(answer,index+1,ds,nums);
        ds.pop_back(); //backtrack
        //exclude
        solve(answer,index+1,ds,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> ds;
        solve(answer,0,ds,nums);
        return answer;
    }
};