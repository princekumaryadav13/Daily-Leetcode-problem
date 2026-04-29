class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

         int sum =0;
         vector<int>vec;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
              vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());

        int rem = vec[0] % x;
        for(int num : vec) {
            if(num % x != rem) return -1;
        }
        int median = vec[vec.size()/2];
        int op =0;

        for(auto it : vec){
            op += abs(it-median)/x;
        }
          return op;
       
    }
};