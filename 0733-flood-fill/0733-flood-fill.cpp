class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor,
             int oldColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        image[sr][sc] = newColor;
        q.push({sr, sc});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (image[nr][nc] == oldColor) {

                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int new_color) {
        // we have given a matrix and we have to do bfs or dfs normal wala
       

        int old_color = image[sr][sc];
         if (old_color == new_color)
        return image;
        bfs(image, sr, sc, new_color, old_color);
        return image;
    }
};