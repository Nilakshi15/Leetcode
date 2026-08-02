class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // start or end blocked
        if (obstacleGrid[0][0] == 1 ||
            obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        // dp[j] = ways to reach current cell
        vector<int> dp(n, 0);

        // starting position
        dp[0] = 1;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // obstacle cell cannot be used
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }

                // add paths from left side
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        // answer at bottom-right
        return dp[n - 1];
    }
};