class Solution {
public:
    void BFS(int start, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        int n = isConnected.size();
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbour = 0; neighbour < n; neighbour++) {
                if (isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
    void DFS(int start, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        int n = isConnected.size();
        visited[start] = true;
        for (int neighbour = 0; neighbour < n; neighbour++) {
            if (isConnected[start][neighbour] == 1 && !visited[neighbour]) {
                DFS(neighbour, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                DFS(node, isConnected, visited);
                ans++;
            }
        }
        return ans;
    }
};