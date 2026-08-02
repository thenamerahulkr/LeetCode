class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find with Path Compression 
    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    // Union by Rank; returns true if a merge occurred
    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) {
            return false; // Already in the same component
        }

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }

        return true;
    }
};
class Solution {
private:
    // void bfs(int startNode, const vector<vector<int>>& adj, vector<bool>&
    // visited) {
    //     queue<int> q;
    //     q.push(startNode);
    //     visited[startNode] = true;

    //     while (!q.empty()) {
    //         int curr = q.front();
    //         q.pop();

    //         for (int neighbor : adj[curr]) {
    //             if (!visited[neighbor]) {
    //                 visited[neighbor] = true;
    //                 q.push(neighbor);
    //             }
    //         }
    //     }
    // }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //     if (connections.size() < n - 1) {
        //         return -1;
        //     }
        //     vector<vector<int>> adj(n);
        //     for (const auto& conn : connections) {
        //         adj[conn[0]].push_back(conn[1]);
        //         adj[conn[1]].push_back(conn[0]);
        //     }
        //     vector<bool> visited(n, false);
        //     int components = 0;

        //     for (int i = 0; i < n; ++i) {
        //         if (!visited[i]) {
        //             components++;
        //             bfs(i, adj, visited);
        //         }
        //     }
        //     return components - 1;
        // }
        if (connections.size() < n - 1) {
            return -1;
        }
        DisjointSet ds(n);
        int components = n;

        for (const auto& conn : connections) {
            if (ds.unionSets(conn[0], conn[1])) {
                components--;
            }
        }
        return components - 1;
    }
};