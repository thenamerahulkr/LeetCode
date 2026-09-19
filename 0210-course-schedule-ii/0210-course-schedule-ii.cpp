class Solution {
public:
    void topoSort(int& count, int i, vector<int>& indegree, vector<vector<int>>& adj, vector<int>& ans) {
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(!indegree[i]) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(!indegree[neighbour]) q.push(neighbour);
            }
        }
        // return count == adj.size();
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        int count = 0;
        topoSort(count,0, indegree, adj, ans);
        if(count != numCourses) return {};
        return ans;
    }
};