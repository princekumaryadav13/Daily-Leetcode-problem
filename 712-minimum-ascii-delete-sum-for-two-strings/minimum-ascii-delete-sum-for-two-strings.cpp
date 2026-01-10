class Solution {
public:
    int solve(string& s1, string& s2, int i, int j,vector<vector<int>>& dp) {
        if (i == s1.size() && j == s2.size())
            return 0;
        if (i == s1.size()) {
            int sum = 0;
            while (j < s2.size()) {
                sum += s2[j];
                j++;
            }
            return sum;
        }
        if (j == s2.size()) {
            int sum = 0;
            while (i < s1.size()) {
                sum += s1[i];
                i++;
            }
            return sum;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minsum = 0;
        if (s1[i] == s2[j]) {
            return dp[i][j]= solve(s1, s2, i + 1, j + 1,dp);
        } else {
            minsum = min(s1[i] + solve(s1, s2, i + 1, j,dp),
                         s2[j] + solve(s1, s2, i, j + 1,dp));
        }
        return dp[i][j]= minsum;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
         return solve(s1, s2, 0, 0,dp);
          }
};