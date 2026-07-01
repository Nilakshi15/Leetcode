class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : s)
            freq[ch]++;

        int ans = 0;
        bool odd = false;

        for (auto &it : freq) {

            // Use all even occurrences
            if (it.second % 2 == 0) {
                ans += it.second;
            }

            // Use count - 1 for odd occurrences
            else {
                ans += it.second - 1;
                odd = true;
            }
        }

        // One odd character can be placed in the center
        if (odd)
            ans++;

        return ans;
    }
};