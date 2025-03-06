class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int row = grid.size();
        int col = grid[0].size();
        unordered_map<int,int> mp;
        int x = row*row;
        int total_sum = x*(x+1)/2;
        for(int i=0; i<row; i++){
            for(int j =0; j<col; j++){
                int key = grid[i][j];
                mp[key]++;
            }
        }
        int sum_key = 0;
        for(auto ele: mp){
            sum_key += ele.first;
            if(ele.second == 2){
                ans.push_back(ele.first);
            }
        }
        ans.push_back(total_sum - sum_key);
        return ans;
    }
};