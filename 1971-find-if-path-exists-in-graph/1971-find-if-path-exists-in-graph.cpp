class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);

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
    void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV) {
            return;
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
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        int total_component = n;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int pu = dsu.findParent(u);
            int pv = dsu.findParent(v);
            if(pu != pv){
                total_component--;
                dsu.unionByRank(u,v);
            }
        }
        if(dsu.findParent(source) == dsu.findParent(destination)) return true;

        return false;
    }   
};