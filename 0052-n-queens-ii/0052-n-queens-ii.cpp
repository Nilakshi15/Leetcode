class Solution {
public:
    int ans = 0;

    void backtrack(int row, int n,
                   vector<bool>& col,
                   vector<bool>& diag1,
                   vector<bool>& diag2) {

        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {

            if (col[c] || diag1[row + c] || diag2[row - c + n - 1])
                continue;

            col[c] = true;
            diag1[row + c] = true;
            diag2[row - c + n - 1] = true;

            backtrack(row + 1, n, col, diag1, diag2);

            col[c] = false;
            diag1[row + c] = false;
            diag2[row - c + n - 1] = false;
        }
    }

    int totalNQueens(int n) {

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(0, n, col, diag1, diag2);

        return ans;
    }
};