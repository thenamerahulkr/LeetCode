class Solution {
public:
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffSet, int colOffSet) {
        int n = A.size();
        int countCommon = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int b_i = i + rowOffSet;
                int b_j = j + colOffSet;
                if (b_i < 0 || b_i >= n || b_j < 0 || b_j >= n)
                    continue;
                if (A[i][j] == 1 && B[b_i][b_j])
                    countCommon++;
            }
        }
        return countCommon;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverLap = 0;
        for (int rowOffSet = -n + 1; rowOffSet < n; rowOffSet++) {
            for (int colOffSet = -n + 1; colOffSet < n; colOffSet++) {
                maxOverLap =
                    max(maxOverLap, countOverlap(A, B, rowOffSet, colOffSet));
            }
        }
        // int count1 = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (A[i][j] == 1) {
        //             count1++;
        //         }
        //     }
        // }
        // int count2 = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (B[i][j] == 1) {
        //             count2++;
        //         }
        //     }
        // }
        // if(count1 == 0 and count2 == 0) return 0;
        // return min(count1, count2);
        return maxOverLap;
    }
};