class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);

        // Count frequency
        for (char ch : s)
            freq[ch - 'a']++;

        string st;

        for (char ch : s) {

            freq[ch - 'a']--;

            // Already present
            if (inStack[ch - 'a'])
                continue;

            // Remove bigger chars if they appear later
            while (!st.empty() &&
                   st.back() > ch &&
                   freq[st.back() - 'a'] > 0) {

                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            inStack[ch - 'a'] = true;
        }

        return st;
    }
};