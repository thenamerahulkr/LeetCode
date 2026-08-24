class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(
            m, vector<int>(n, INT_MAX)
        );

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto [effort, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            // stale entry
            if (effort > dist[x][y])
                continue;

            // Destination reached
            if (x == m - 1 && y == n - 1)
                return effort;

            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n)
                    continue;

                int diff = abs(
                    heights[x][y] - heights[nx][ny]
                );

                int newEffort = max(effort, diff);

                if (newEffort < dist[nx][ny]) {

                    dist[nx][ny] = newEffort;

                    pq.push({
                        newEffort,
                        {nx, ny}
                    });
                }
            }
        }

        return 0;
    }
};