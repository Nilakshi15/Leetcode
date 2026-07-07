class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> window;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            // Remove duplicates from the left
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            // Add current character
            window.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};