class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = find(parent[node]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
            swap(pu, pv);

        parent[pv] = pu;
        size[pu] += size[pv];
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        DSU dsu(26);
        for(int i = 0; i < n; i++){
            char ch1 = equations[i][0];
            char ch2 = equations[i][3];
            if(equations[i][1] == '=' and equations[i][2] == '='){
                // union
                int u = ch1 - 'a';
                int v = ch2 - 'a';
                dsu.Union(u,v);
            }
        }
        for(int i = 0; i < n; i++){
           char ch1 = equations[i][0];
            char ch2 = equations[i][3];
            if(equations[i][1] == '!' and equations[i][2] == '='){

                int u = ch1 - 'a';
                int v = ch2 - 'a';
                int pu = dsu.find(u);
                int pv = dsu.find(v);
                if(pu == pv) return false;
            }
        }
        return true;
    }
};