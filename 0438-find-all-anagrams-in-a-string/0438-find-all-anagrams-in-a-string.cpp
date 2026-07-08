class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> freq(26, 0);

        // Count frequency of characters in p
        for (char ch : p)
            freq[ch - 'a']++;

        int left = 0;
        int right = 0;
        int required = p.size();

        while (right < s.size()) {

            // Current character helps satisfy p
            if (freq[s[right] - 'a'] > 0)
                required--;

            freq[s[right] - 'a']--;
            right++;

            // Window size reached
            if (right - left == p.size()) {

                // Found an anagram
                if (required == 0)
                    ans.push_back(left);

                // Remove left character
                if (freq[s[left] - 'a'] >= 0)
                    required++;

                freq[s[left] - 'a']++;
                left++;
            }
        }

        return ans;
    }
};