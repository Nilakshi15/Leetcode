class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        // Only number is 0
        if (n == 0)
            return 1;

        int ans = 10;      // count for n = 1
        int unique = 9;    // first digit choices
        int available = 9; // remaining digits

        for (int len = 2; len <= n; len++) {

            unique *= available;

            ans += unique;

            available--;
        }

        return ans;
    }
};