class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
      /**    return min(1.0, rec(poured, query_row, query_glass));
    }

private:
    double rec(int poured, int row, int glass) {
        if (row < 0 || glass < 0 || glass > row) {
            return 0;
        }

        if (row == 0 && glass == 0) {
            return poured;
        }

        double leftParent = max(0.0, rec(poured, row - 1, glass - 1) - 1);
        double rightParent = max(0.0, rec(poured, row - 1, glass) - 1);

        return (leftParent + rightParent) / 2; 
        **/
          vector<vector<double>> memo(query_row + 5);
        for (int i = 0; i <= query_row + 4; i++) {
            memo[i].resize(i + 1, -1);
        }

        memo[0][0] = poured;
        return min(1.0, rec(memo, query_row, query_glass));
    }

private:
    double rec(vector<vector<double>>& memo, int row, int glass) {
        if (row < 0 || glass < 0 || glass > row) {
            return 0;
        }
        
        if (memo[row][glass] != -1) {
            return memo[row][glass];
        }

        double leftParent = max(0.0, rec(memo, row - 1, glass - 1) - 1);
        double rightParent = max(0.0, rec(memo, row - 1, glass) - 1);

        memo[row][glass] = (leftParent + rightParent) / 2;
        return memo[row][glass];
    }
};