class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Two intervals [start1, end1] and [start2, end2] intersect 
                // if max(start1, start2) <= min(end1, end2)
                if (max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};