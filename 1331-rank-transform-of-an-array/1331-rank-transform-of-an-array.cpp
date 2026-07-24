class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Your code goes here
        // element and their index
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>  pq;
                       
        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
        }
        int rank = 0;
        vector<int> ans(arr.size(), 0);
        int prev_ele = -1e9 - 7;
        while (!pq.empty()) {
            int ele = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if (ele != prev_ele) {
                rank++;
            }
            ans[idx] = rank;
            prev_ele = ele;
        }
        return ans;
    }
};