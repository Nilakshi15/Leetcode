class Solution {
public:

    int numDecodings(string s) {

        int n = s.size();
        if (s[0] == '0')
            return 0;

        // dp[i] = ways to decode first i characters
        vector<int> dp(n + 1, 0);

        // empty string has one way
        dp[0] = 1;

        // first character already checked
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {

            // take single digit
            int oneDigit = s[i - 1] - '0';

            if (oneDigit >= 1 && oneDigit <= 9)
                dp[i] += dp[i - 1];

            // take two digits
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if (twoDigits >= 10 && twoDigits <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};