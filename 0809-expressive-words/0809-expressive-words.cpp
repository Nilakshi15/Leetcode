class Solution {
public:
    bool check(string s, string word) {

        int i = 0, j = 0;

        while (i < s.size() && j < word.size()) {

            if (s[i] != word[j])
                return false;

            int iStart = i;
            int jStart = j;

            while (i < s.size() && s[i] == s[iStart])
                i++;

            while (j < word.size() && word[j] == word[jStart])
                j++;

            int lenS = i - iStart;
            int lenW = j - jStart;

            if (lenS < lenW)
                return false;

            if (lenS != lenW && lenS < 3)
                return false;
        }

        return i == s.size() && j == word.size();
    }

    int expressiveWords(string s, vector<string>& words) {

        int ans = 0;

        for (string word : words) {
            if (check(s, word))
                ans++;
        }

        return ans;
    }
};