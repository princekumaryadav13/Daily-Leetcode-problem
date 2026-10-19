class Solution {
public:
    int n, m;
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        check(board);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void check(vector<vector<char>>& board) {
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 ||
                    j == n - 1 && board[i][j] == 'O') {
                    que.push({i, j});
                }
            }
        }
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            if (board[x][y] == 'O') {
                board[x][y] = 'T';

                for (auto& d : dirs) {
                    int nr = x + d[0];
                    int nc = y + d[1];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                        que.push({nr, nc});
                    }
                }
            }
        }
    }
};