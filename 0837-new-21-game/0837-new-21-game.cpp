class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        // If Alice stops before reaching k, she can never exceed n.
        if (k == 0 || n >= k + maxPts - 1)
            return 1.0;

        vector<double> dp(n + 1, 0.0);

        // dp[x] = probability of reaching exactly x points
        dp[0] = 1.0;

        double windowSum = 1.0;
        double ans = 0.0;

        for (int x = 1; x <= n; x++) {

            dp[x] = windowSum / maxPts;

            // Once x >= k, Alice stops.
            if (x >= k)
                ans += dp[x];
            else
                windowSum += dp[x];

            // Remove the value that is no longer in the window.
            if (x - maxPts >= 0 && x - maxPts < k)
                windowSum -= dp[x - maxPts];
        }

        return ans;
    }
};