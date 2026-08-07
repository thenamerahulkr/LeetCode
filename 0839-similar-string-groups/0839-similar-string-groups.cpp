class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

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

    // True means union happened
    bool unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) {
            return false;
        }

        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        }
        else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        }
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }

        return true;
    }
};
void bfs(int start, vector<vector<int>>& adj, vector<bool>& vis) {
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
class Solution {
public:
    bool isSimilar(const string& str1, const string& str2) {
        int diff = 0;

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                diff++;

                // 2 se zyada difference hua to similar nahi honge
                if (diff > 2) {
                    return false;
                }
            }
        }

        return diff == 0 || diff == 2;
    }


    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        // DSU dsu(n);
        // int components = n;
        // 
        // // Har string ko baaki sabhi strings se compare karo
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {

        //         if (isSimilar(strs[i], strs[j])) {

        //             // Different components the, isliye merge hua
        //             if (dsu.unionByRank(i, j)) {
        //                 components--;
        //             }
        //         }
        //     }
        // }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                if (isSimilar(strs[i], strs[j])) {
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int count = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bfs(i, adj, visited);
                count++;
            }
        }
        return count;
        // return components;
    }
};