class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Count current character
            freq[s[right] - 'A']++;

            // Maximum frequency in current window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Too many replacements needed
            while ((right - left + 1) - maxFreq > k) {

                freq[s[left] - 'A']--;
                left++;
            }

            // Update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};