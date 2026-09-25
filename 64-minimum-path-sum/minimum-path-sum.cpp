class Solution {
public:
     int m , n;
  //   int ans =0;
     int  solve(int i , int j ,vector<vector<int>>& grid, vector<vector<int>>&dp ){
       if(i==m-1 && j==n-1){
         return grid[i][j] ;
       }
      if(i == m || j == n)
        return INT_MAX;

      if(dp[i][j]!=INT_MAX){
        return dp[i][j];
      }  

       return dp[i][j] =  grid[i][j]+ min(solve(i+1,j,grid,dp),solve(i,j+1,grid,dp));

      
     }
    int minPathSum(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

         vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

        return solve(0,0,grid,dp);

        
    }
};