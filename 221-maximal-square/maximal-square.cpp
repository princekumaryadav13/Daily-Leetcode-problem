class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(col, 0));
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1],
                                        dp[i - 1][j - 1]}) +
                                   1;
                    }
                    count = max(count, dp[i][j]);
                }
            }
        }
        return count * count;
    }
};