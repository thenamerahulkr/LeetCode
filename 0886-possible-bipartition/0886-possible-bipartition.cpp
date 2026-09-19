class Solution {
public:
    bool bfs(int startNode, vector<vector<int>>& adj, vector<int>& color,
             int currColor) {
        queue<pair<int, int>> q;
        q.push({startNode, currColor});
        color[startNode] = currColor;
        while (!q.empty()) {
            auto [node, nodeColor] = q.front();
            q.pop();
            for (auto neighbour : adj[node]) {
                if (color[neighbour] != -1 && color[neighbour] == nodeColor)
                    return false;
                if (color[neighbour] == -1) {
                    color[neighbour] = 1 - nodeColor;
                    q.push({neighbour, 1 - nodeColor});
                }
            }
        }
        return true;
    }
    bool dfs(int startNode, vector<vector<int>>& adj, vector<int>& color,
             int currColor) {
        color[startNode] = currColor;
        for (auto neighbour : adj[startNode]) {
            if (color[neighbour] != -1 && color[neighbour] == currColor)
                return false;
            if (color[neighbour] == -1) {
                color[neighbour] = 1 - currColor;
                if (!dfs(neighbour, adj, color, 1 - currColor))
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto edge : dislikes) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int currColor = 0;
        vector<int> color(n + 1, -1);
        int result = true;
        for (int i = 1; i < n; i++) {
            if (color[i] == -1) {
                result = bfs(i, adj, color, currColor);
                if (!result)
                    return false;
            }
        }
        return result;
    }
};