class Solution {
public:
    int dirs[2][2] = {{1, 0}, {0, 1}};
    int check(vector<vector<int>>& memo, int m, int n, int i, int j) {
        if ((i == m - 1) && (j == n - 1)) {
            return 1;
        }
        if (i >= m || j >= n)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        int cc = 0;
        for (auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            cc += check(memo, m, n, ni, nj);
        }
        return memo[i][j] = cc;
    }
    int uniquePaths(int m, int n) {
        //   int count=0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return check(memo, m, n, 0, 0);
    }
};