class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        // Count characters in t
        for (char ch : t)
            need[ch]++;

        int required = t.size();   // Characters still needed
        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // If current character is needed
            if (need[s[right]] > 0)
                required--;

            need[s[right]]--;

            // Valid window found
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                need[s[left]]++;

                // Window becomes invalid
                if (need[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return (minLen == INT_MAX)
               ? ""
               : s.substr(start, minLen);
    }
};