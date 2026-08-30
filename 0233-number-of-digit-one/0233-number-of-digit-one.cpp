class Solution {
public:
    int countDigitOne(int n) {

        long long factor = 1;
        int ans = 0;

        while (factor <= n) {

            long long lower = n % factor;
            long long current = (n / factor) % 10;
            long long higher = n / (factor * 10);

            if (current == 0) {
                ans += higher * factor;
            }
            else if (current == 1) {
                ans += higher * factor + lower + 1;
            }
            else {
                ans += (higher + 1) * factor;
            }

            factor *= 10;
        }

        return ans;
    }
};