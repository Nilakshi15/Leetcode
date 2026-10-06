class Solution {
public:
    int ans = 0;

    void solve(int pos, int n, vector<bool>& used) {

        // All positions are filled
        if (pos > n) {
            ans++;
            return;
        }

        for (int num = 1; num <= n; num++) {

            // Number should not be used
            // and should satisfy the condition
            if (!used[num] &&
                (num % pos == 0 || pos % num == 0)) {

                used[num] = true;

                solve(pos + 1, n, used);

                // Backtrack
                used[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);

        solve(1, n, used);

        return ans;
    }
};