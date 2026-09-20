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
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        int currColor = 0;
        vector<int> color(n, -1);
        int result = true;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                result = bfs(i, adj, color, currColor);
                if (!result)
                    return false;
            }
        }
        return result;
    }
};