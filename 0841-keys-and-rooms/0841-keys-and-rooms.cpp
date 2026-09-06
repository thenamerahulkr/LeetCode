class Solution {
public:
    void dfs(int src, vector<bool>& visited, vector<vector<int>>& rooms) {
        visited[src] = true;
        for (auto& neighbour : rooms[src]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        // return all true or not
        dfs(0, visited, rooms);
        for (bool element : visited) {
            if (element == false)
                return false;
        }
        return true;
    }
};