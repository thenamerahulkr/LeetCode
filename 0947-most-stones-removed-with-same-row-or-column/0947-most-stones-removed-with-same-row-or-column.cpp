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

    int countComponents() {
        int componentCount = 0;

        for (int i = 0; i < parent.size(); i++) {
            if (findParent(i) == i) {
                componentCount++;
            }
        }

        return componentCount;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    dsu.unionByRank(i, j);
                }
            }
        }

        int components = dsu.countComponents();

        return n - components;
    }
};