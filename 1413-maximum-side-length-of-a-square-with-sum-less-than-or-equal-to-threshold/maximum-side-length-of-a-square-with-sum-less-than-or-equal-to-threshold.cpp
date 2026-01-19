class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> prefix(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                prefix[i][j] = mat[i][j] + (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        auto sumsquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];
            if (i > 0)
                sum -= prefix[i - 1][c2];
            if (j > 0)
                sum -= prefix[r2][j - 1];
            if (i > 0 && j > 0)
                sum += prefix[i - 1][j - 1];
            return sum;
        };

        int best = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < min(row - i, col - j); k++) {
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = sumsquare(i, j, r2, c2);
                    if (sum <= threshold)
                        best = max(best, k + 1);
                    else
                        break;
                }
            }
        }

        return best;
    }
};