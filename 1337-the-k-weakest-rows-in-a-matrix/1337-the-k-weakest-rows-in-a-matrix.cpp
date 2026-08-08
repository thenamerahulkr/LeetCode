class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        /*
            -> ek heap le lo min wala
            pair -> count , index;
            pair bnao usme index k sath uska count store kro per row ka and heap
           me daal do phir k weakest array me store kr k return kr do

        */
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        for (int i = 0; i < mat.size(); i++) {     
            int count_rows_1s = 0;
            // pair<int, int> p;
            for (int j = 0; j < mat[0].size(); j++) { 
               if(mat[i][j] == 1){
                count_rows_1s++;
               }
            }
            // p.first = count_rows_1s;
            // p.second = i;
            minHeap.push({count_rows_1s, i});
        }
        vector<int> ans;
        while(k > 0){
            auto [c, i] = minHeap.top();
            minHeap.pop();
            k--;
            ans.push_back(i);
        }
        return ans;
    }
};