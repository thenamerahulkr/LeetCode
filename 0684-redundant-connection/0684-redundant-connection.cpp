class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        // Union by size
        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        DSU dsu(V + 1);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int pu = dsu.find(u);
            int pv = dsu.find(v);
            if(pu == pv){
                return {u, v};
            }
            else if(pu != pv){
                // union
                dsu.Union(u, v);
            }
        }
        return {};
    }
};