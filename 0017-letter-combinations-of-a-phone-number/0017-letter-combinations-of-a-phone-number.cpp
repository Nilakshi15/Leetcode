class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int index, string &digits, string &curr) {

        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {

            curr.push_back(ch);

            backtrack(index + 1, digits, curr);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        string curr;

        backtrack(0, digits, curr);

        return ans;
    }
};