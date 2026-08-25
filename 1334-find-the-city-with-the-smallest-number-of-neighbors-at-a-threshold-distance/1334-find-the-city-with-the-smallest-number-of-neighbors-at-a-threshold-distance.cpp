class Solution {
    vector<vector<int>> shortestPath;
    const int INF = 1e8;

public:
    void go_via_k(vector<vector<int>>& shortestPath, int k) {
        int n = shortestPath.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (shortestPath[i][k] != INF && shortestPath[k][j] != INF) {

                    shortestPath[i][j] =
                        min(shortestPath[i][j],
                            shortestPath[i][k] + shortestPath[k][j]);
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        shortestPath.resize(n, vector<int>(n, INF));
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            shortestPath[u][v] = min(shortestPath[u][v], wt);
            shortestPath[v][u] = min(shortestPath[v][u], wt);
        }
        for (int k = 0; k < n; k++) {
            go_via_k(shortestPath, k);
        }
        // Find city with minimum reachable cities
        int minCount = INT_MAX;
        int ans = -1;

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (i != j && shortestPath[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // <= handles tie: choose greater city number
            if (count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};