class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();

        int r = k % col;
        vector<vector<int>> temp = mat;
        vector<vector<int>> t = mat;
        while (r > 0) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (i % 2 == 0) {
                        if (j != col - 1) {
                            temp[i][j] = mat[i][j + 1];
                        } else {
                            temp[i][j] = mat[i][0];
                        }
                    } else {
                        if (j == 0) {
                            temp[i][j] = mat[i][col - j - 1];
                        } else {
                            temp[i][j] = mat[i][j - 1];
                        }
                    }
                }
            }
            mat = temp ;
            r--;
        }
        return mat == t;
    }
};