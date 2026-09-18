class Solution {
public:
    bool dfs(int r, int c, int index, vector<vector<char>>& board, const string& word){
        if (index == word.length()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(r + 1, c, index + 1, board, word) ||
                     dfs(r - 1, c, index + 1, board, word) ||
                     dfs(r, c + 1, index + 1, board, word) ||
                     dfs(r, c - 1, index + 1, board, word);
        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == word[0] && dfs(r, c, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};