class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        // Build the answer from left to right
        for (int i = 1; i <= n; i++) {

            // Try every possible previous break point
            for (int j = 0; j < i; j++) {

                // If prefix till j is valid
                // and substring j -> i-1 exists in dictionary
                if (dp[j] &&
                    words.count(s.substr(j, i - j))) {

                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};