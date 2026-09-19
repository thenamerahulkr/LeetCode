class Solution {
public:
    bool dfs(int startNode, vector<int>& visited, vector<int>& pathVisited, vector<vector<int>> & adj)
	{
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
	bool isCyclic(int V, vector<vector<int>> &edges) {
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
        return !isCyclic(numCourses,prerequisites);
    }
};