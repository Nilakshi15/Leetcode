// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// The API is already defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        long long left = 1;
        long long right = n;

        while (left < right) {

            // Prevent overflow
            long long mid = left + (right - left) / 2;

            if (isBadVersion(mid))
                right = mid;      // First bad is at mid or before
            else
                left = mid + 1;   // First bad is after mid
        }

        return left;
    }
};