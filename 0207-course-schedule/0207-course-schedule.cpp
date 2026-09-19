class Solution {
public:
    bool topoSort(int i, vector<int>& indegree, vector<vector<int>>& adj) {
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(!indegree[i]) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(!indegree[neighbour]) q.push(neighbour);
            }
        }
        return count == adj.size();
    }
    bool dfs(int startNode, vector<int>& visited, vector<int>& pathVisited,
             vector<vector<int>>& adj) {
        visited[startNode] = 1;
        pathVisited[startNode] = 1;
        for (int i = 0; i < adj[startNode].size(); i++) {
            int neighbor = adj[startNode][i];
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, pathVisited, adj))
                    return true;
            } else {
                if (pathVisited[neighbor])
                    return true;
            }
        }

        pathVisited[startNode] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> visited(V, 0), pathVisited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited, adj))
                    return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        return topoSort(0, indegree, adj);
        // return !isCyclic(numCourses,prerequisites);
    }
};