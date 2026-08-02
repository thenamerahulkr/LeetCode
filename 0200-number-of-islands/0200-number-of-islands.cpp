class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m * n);
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1')
                    islands++;
            }
        }

        int dr[] = {0, 1};
        int dc[] = {1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0')
                    continue;

                int node = i * n + j;

                for (int k = 0; k < 2; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= m || nc >= n)
                        continue;

                    if (grid[nr][nc] == '0')
                        continue;

                    int adj = nr * n + nc;

                    if (dsu.Union(node, adj))
                        islands--;
                }
            }
        }

        return islands;
    }
};