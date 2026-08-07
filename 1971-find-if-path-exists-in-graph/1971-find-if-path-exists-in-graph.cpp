class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }
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
    }

    bool isConnected(int u, int v) { return findParent(u) == findParent(v); }
};
class Solution {
public:
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        // visitt kro neighbout
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // visit all neighbours of current node
            for (auto neighbour : adj[node]) {

                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        // DSU dsu(n);
        // int total_component = n;
        // for(auto &edge : edges){
        //     int u = edge[0];
        //     int v = edge[1];
        //     int pu = dsu.findParent(u);
        //     int pv = dsu.findParent(v);
        //     if(pu != pv){
        //         total_component--;
        //         dsu.unionByRank(u,v);
        //     }
        // }
        // if(dsu.findParent(source) == dsu.findParent(destination)) return
        // true;

        // return false;
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // yhse se nowmal bfs ya dfs krna hai and number of component nikalna
        // hai ! if 1 hai to true ni to false;
        vector<bool> visited(n, false);

        bfs(source, adj, visited);

        return visited[destination];
    }
};