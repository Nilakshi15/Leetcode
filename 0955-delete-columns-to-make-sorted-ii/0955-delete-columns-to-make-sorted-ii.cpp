class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int m = strs.size();
        int n = strs[0].size();

        vector<bool> sorted(m - 1, false);
        int ans = 0;

        for (int col = 0; col < n; col++) {

            bool bad = false;

            // Check whether this column violates ordering
            for (int row = 0; row < m - 1; row++) {

                if (!sorted[row] &&
                    strs[row][col] > strs[row + 1][col]) {

                    bad = true;
                    break;
                }
            }

            // Delete this column
            if (bad) {
                ans++;
                continue;
            }

            // This column is safe.
            // Mark pairs whose order is now determined.
            for (int row = 0; row < m - 1; row++) {

                if (strs[row][col] < strs[row + 1][col])
                    sorted[row] = true;
            }
        }

        return ans;
    }
};