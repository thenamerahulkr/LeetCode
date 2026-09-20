class Solution {
public:
    // boundary se bfs ya dfs lga do 
    typedef pair<int,int> p;
    void bfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<p> q;
        vector<vector<int>> dir = {
            {0, 1},
        {-1, 0},    {1, 0},
            {0, -1}
        };
        q.push({row,col});
        grid[row][col] = 0;
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++){
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1) bfs(0, i, grid);
        }
        for(int i = 0; i < n; i++){
            if(grid[m-1][i] == 1) bfs(m-1, i, grid);
        }
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) bfs(i, 0, grid);
        }
        for(int i = 0; i < m; i++){
            if(grid[i][n-1] == 1) bfs(i, n-1, grid);
        }
        // count number of ones in matrix
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};