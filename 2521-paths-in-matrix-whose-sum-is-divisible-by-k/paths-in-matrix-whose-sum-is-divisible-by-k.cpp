class Solution {
public:
     static const int MOD = 1e9 + 7;
    int directions[2][2] = {{0, 1}, {1, 0}  } ;  //   , {0, -1}, {-1, 0}};
    int solve(vector<vector<int>>& grid, int k, int i, int j, int path_sum ,vector<vector<vector<int>>>&dp) {
         path_sum = (path_sum + grid[i][j]) % k;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            if (path_sum  == 0) {
                return 1;
            } else {
                return 0;
            }
        }
         int &ans = dp[i][j][path_sum ];
        if (ans != -1) return ans;

        
        long long count = 0;
        for (auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if (i_ >= 0 && j_ >= 0 && i_ < grid.size() && j_ < grid[0].size()) {
                count += solve(grid, k, i_, j_, path_sum ,dp);
            }
        }
        ans = count % MOD;
        return ans ;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
       vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k, -1)));
        return solve(grid, k, 0, 0, 0,dp);
    }
};