class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_by_pc(int node) {
        if (node == parent[node]) {
            return node;
        }

        int ultimateParent = find_by_pc(parent[node]);

        parent[node] = ultimateParent;

        return ultimateParent;
    }
    void union_by_rank(int x, int y) {
        int px = find_by_pc(x);
        int py = find_by_pc(y);
        if (px == py)
            return;
        if (rank[px] > rank[py]) {
            // papa x banega
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            // py root/papa banega
            parent[px] = py;
        } else {
            // Dono ki rank same hai, kisi ko bhi parent bana sakte hain
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int pu = dsu.find_by_pc(u);
            int pv = dsu.find_by_pc(v);

            if (pu != pv) {
                dsu.union_by_rank(u, v);
            }
        }
        unordered_map<int, long long> componentSize;

        for (int i = 0; i < n; i++) {
            int root = dsu.find_by_pc(i);
            componentSize[root]++;
        }
        long long answer = 0;
        long long remainingNodes = n;
        for (auto &it : componentSize) {
            long long currentSize = it.second;

            remainingNodes -= currentSize;

            answer += currentSize * remainingNodes;
        }

        return answer;
    }
};