class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;
        for(auto &r : grid)
            for(int x : r)
                total += x;

        // ❗ Important fix
        if(total % 2 != 0) return false;

        long long target = total / 2;

        // 🔹 Check horizontal cut
        long long prefix = 0;
        for(int i = 0; i < m - 1; i++) {
            long long rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            prefix += rowSum;

            if(prefix == target)
                return true;
        }

        // 🔹 Check vertical cut
        prefix = 0;
        for(int j = 0; j < n - 1; j++) {
            long long colSum = 0;
            for(int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            prefix += colSum;

            if(prefix == target)
                return true;
        }

        return false;
    }
};