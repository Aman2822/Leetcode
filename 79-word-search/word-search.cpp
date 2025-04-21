class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();

    function<bool(int, int, int)> dfs = [&](int i, int j, int index) {
        if (index == word.length()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';  // Mark as visited

        bool found = dfs(i+1, j, index+1) ||
                     dfs(i-1, j, index+1) ||
                     dfs(i, j+1, index+1) ||
                     dfs(i, j-1, index+1);

        board[i][j] = temp;  // Backtrack
        return found;
    };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;
}

};