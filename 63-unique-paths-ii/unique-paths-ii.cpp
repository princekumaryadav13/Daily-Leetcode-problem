class Solution {
public:
    int n, m;
     int solve(int i ,int j, vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(i==m-1 &&j == n-1){
            return 1;
        }
        if(i>=m || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        return dp[i][j] = solve(i+1,j,obstacleGrid,dp)+solve(i,j+1,obstacleGrid,dp);
     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         m = obstacleGrid.size();
         n= obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1)return 0; 

        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

       return solve(0,0,obstacleGrid,dp);
    }
};