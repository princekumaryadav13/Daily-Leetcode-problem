class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        // Use a very small value to represent impossible states
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN / 2));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int product = nums1[i - 1] * nums2[j - 1];
                
                // Take current pair (start new or extend previous)
                int take = max(product, dp[i - 1][j - 1] + product);
                
                // Skip one element
                dp[i][j] = max({take, dp[i - 1][j], dp[i][j - 1]});
            }
        }
        
        return dp[n][m];
    }
};
