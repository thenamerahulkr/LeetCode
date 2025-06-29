class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int right_sum = 0;
        int left_sum = 0;
        int max_points = 0;
        for(int i = 0; i<k; i++){
            left_sum += cardPoints[i];
            max_points = max(max_points,left_sum);
        }
        int index = n-1;
        for(int j = k-1; j>=0; j--){
            left_sum -= cardPoints[j];
            right_sum += cardPoints[index];
            index--;
            max_points = max(right_sum+left_sum, max_points);
        }
        return max_points;
    }
};