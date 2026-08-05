class Solution {
public:
    void DFS(int start_node, vector<vector<int>>& adj,vector<bool>& suspicious) {
        suspicious[start_node] = true;
        for (auto& neighbour : adj[start_node]) {
            if (!suspicious[neighbour]) {
                DFS(neighbour, adj, suspicious);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        // we have adj list ready
        // we have to call bfs or dfs from k
        vector<bool> suspicious(n, false);
        DFS(k, adj, suspicious);
        bool can_we_remove = true;
        for (auto edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!suspicious[u] and suspicious[v]) {
                can_we_remove = false;
            }
        }
        vector<int> node;
        if (!can_we_remove) {
            for (int i = 0; i < n; i++) {
                node.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!suspicious[i])
                    node.push_back(i);
            }
        }
        return node;
    }
};