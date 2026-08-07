class DSU {
private:
    vector<int> size;
    vector<int> parent;

public:

    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void union_by_size(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (size[px] > size[py]) {

            parent[py] = px;
            size[px] += size[py];

        } 
        else {

            parent[px] = py;
            size[py] += size[px];
        }
    }
};


class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int m = isConnected[0].size();
        DSU dsu(n + n);

        // connect cities
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (isConnected[i][j] == 1) {
                    dsu.union_by_size(i, j);
                }
            }
        }

        // count components
        int provinces = 0;

        for (int i = 0; i < n; i++) {

            if (dsu.find(i) == i) {
                provinces++;
            }
        }

        return provinces;
    }
};