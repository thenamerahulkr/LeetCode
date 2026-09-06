class Solution {
public:
    void bfs(int src, vector<bool>& visited, vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbour : rooms[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
    // void dfs(int src, vector<bool>& visited, vector<vector<int>>& rooms) {
    //     visited[src] = true;
    //     for (auto& neighbour : rooms[src]) {
    //         if (!visited[neighbour]) {
    //             dfs(neighbour, visited, rooms);
    //         }
    //     }
    // }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        // return all true or not
        bfs(0, visited, rooms);
        for (bool element : visited) {
            if (element == false)
                return false;
        }
        return true;
    }
};