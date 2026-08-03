
class Solution {
public:
    int Prims_algo(vector<vector<pair<int, int>>>& adj) {
        int n = adj.size();
        // {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
        vector<int> visited(n, 0);
        minHeap.push({0, 0});
        int mstWeight = 0;
        while(!minHeap.empty()){
            auto [weight, node] = minHeap.top();
            minHeap.pop();
             if (visited[node]) {
                continue;
            }
             visited[node] = 1;
            mstWeight += weight;
             for (auto [neighbour, edgeWeight] : adj[node]) {

                if (!visited[neighbour]) {
                    minHeap.push({edgeWeight, neighbour});
                }
            }
        }
        return mstWeight;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int distance = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, distance});
                adj[j].push_back({i, distance});
            }
        }
        return Prims_algo(adj);
    }
};