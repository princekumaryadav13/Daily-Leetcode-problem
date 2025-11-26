class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int i,int j,long long sum,int n,int m,int k,vector<vector<int>> 
                &grid,vector<vector<vector<int>>> &dp)
    {
        if(i == n-1 && j == m-1)
            return (sum + grid[i][j])%k == 0;
        if(dp[i][j][sum] != -1)
            return dp[i][j][sum];
        long long pick = 0;
        if(i+1<n)
            pick += solve(i+1,j,(sum+grid[i][j])%k,n,m,k,grid,dp);
        if(j+1<m)
            pick += solve(i,j+1,(sum+grid[i][j])%k,n,m,k,grid,dp);
        return dp[i][j][sum] = pick % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return solve(0,0,0,n,m,k,grid,dp);
    }
};