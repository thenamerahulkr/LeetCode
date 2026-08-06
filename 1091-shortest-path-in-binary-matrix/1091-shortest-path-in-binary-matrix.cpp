class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        int n = grid.size();

        // Start ya end blocked hai
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        dist[0][0] = 1;
        q.push({0,0});

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();

            // Destination reached
            if(r == n-1 && c == n-1)
                return dist[r][c];

            for(int k = 0; k < 8; k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= n ||
                   nc < 0 || nc >= n)
                    continue;

                if(grid[nr][nc] == 0 &&
                   dist[nr][nc] > dist[r][c] + 1){

                    dist[nr][nc] = dist[r][c] + 1;

                    q.push({nr,nc});
                }
            }
        }

        return -1;
    }
};