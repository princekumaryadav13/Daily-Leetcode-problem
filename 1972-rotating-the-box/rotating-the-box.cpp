class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>>ans(m, vector<char>(n));
        

        for (int i = 0; i < n; i++) {
            int k = m;
            while (k) {

                for (int j = 0; j < m; j++) {
                    if (boxGrid[i][j] == '#' && j + 1 < m &&
                       boxGrid[i][j + 1] == '.') {
                        swap(boxGrid[i][j], boxGrid[i][j + 1]);
                       
                    }
                }

                k--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n - i - 1] = boxGrid[i][j];
            }
        }
        return ans;
    }
};