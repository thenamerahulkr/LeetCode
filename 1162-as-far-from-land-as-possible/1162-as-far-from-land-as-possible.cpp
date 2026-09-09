class Solution {
public:
    using P = pair<int, int>;
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<P> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        if (q.size() == 0 or q.size() == n * m)
            return -1;
        vector<P> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int distance = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy] : dir){
                    int nx = x + dx;
                    int ny = y + dy;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};