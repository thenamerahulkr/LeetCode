class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i = 0; i<intervals.size(); i++){
            //overlapping condition
            if(merged.back()[1] >= intervals[i][0]){
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};