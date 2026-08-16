class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {

        vector<int> dist(V + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            for (auto [neighbour, weight] : adj[node]) {

                if (distance + weight < dist[neighbour]) {

                    dist[neighbour] = distance + weight;

                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        return dist;
    }

    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int> shortestPath = dijkstra(n, adj, k);

        int ans = 0;

        for (int node = 1; node <= n; node++) {

            if (shortestPath[node] == INT_MAX)
                return -1;

            ans = max(ans, shortestPath[node]);
        }

        return ans;
    }
};