class Solution {
public:
    int count = 0;

    void solve(int pos, int n, vector<bool>& used) {

        // All positions are filled
        if (pos > n) {
            count++;
            return;
        }

        // Try every number
        for (int num = 1; num <= n; num++) {

            // Number is unused and satisfies the condition
            if (!used[num] &&
                (num % pos == 0 || pos % num == 0)) {

                used[num] = true;

                // Fill next position
                solve(pos + 1, n, used);

                // Backtrack
                used[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);

        solve(1, n, used);

        return count;
    }
};