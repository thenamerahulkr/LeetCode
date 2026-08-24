class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(
            m, vector<int>(n, INT_MAX)
        );

        // {cost, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [cost, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            // // stale entry
            // if (cost > dist[x][y])
            //     continue;

            // reached destination
            if (x == m - 1 && y == n - 1)
                return cost < health;

            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n)
                    continue;

                int newCost = cost + grid[nx][ny];

                if (newCost < dist[nx][ny]) {

                    dist[nx][ny] = newCost;

                    pq.push({
                        newCost,
                        {nx, ny}
                    });
                }
            }
        }

        return false;
    }
};