
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find ultimate parent with path compression
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    // Returns false if u and v are already connected
    void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) {
            return;
        }

        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }

        return;
    }
};
class Solution {
public:
    int Prims_algo(vector<vector<pair<int, int>>>& adj) {
        int n = adj.size();
        // {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        vector<int> visited(n, 0);
        minHeap.push({0, 0});
        int mstWeight = 0;
        while (!minHeap.empty()) {
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
    int Kruskal_algo(vector<tuple<int, int, int>>& edges, int V) {
        int mstWeight = 0;
        DSU dsu(V);
        for (auto& temp : edges) {
            int wt = get<0>(temp);
            int u = get<1>(temp);
            int v = get<2>(temp);
            int pu = dsu.findParent(u);
            int pv = dsu.findParent(v);
            if (pu != pv) {
                // we do union
                dsu.unionByRank(u, v);
                mstWeight += wt;
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
        vector<tuple<int, int, int>> edges;

        for (int u = 0; u < n; u++) {
            for (auto [v, wt] : adj[u]) {
                if (u < v) {
                    edges.push_back({wt, u, v});
                }
            }
        }

        sort(edges.begin(), edges.end());

        // return Prims_algo(adj);
        return Kruskal_algo(edges, n);
    }
};