class Solution {
public:
    int n, m;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        // Flood cells till 'day'
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, false));

        // Start from top row
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = true;
            }
        }

        // BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == row - 1) return true;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col &&
                    !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1, high = cells.size(), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canCross(mid, row, col, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
