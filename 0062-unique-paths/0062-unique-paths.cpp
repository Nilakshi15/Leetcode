class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // fill remaining cells
        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                // can come from top or left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // answer at bottom-right cell
        return dp[m - 1][n - 1];
    }
};