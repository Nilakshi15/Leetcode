class Solution {
public:
    void backtrack(string& s, int index, int parts,
                   string curr, vector<string>& ans) {

        if (parts == 4) {
            if (index == s.size()) {
                curr.pop_back(); // remove last '.'
                ans.push_back(curr);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {

            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero
            if (part.size() > 1 && part[0] == '0')
                break;

            int num = stoi(part);

            if (num > 255)
                break;

            backtrack(
                s,
                index + len,
                parts + 1,
                curr + part + ".",
                ans
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;

        if (s.size() < 4 || s.size() > 12)
            return ans;

        backtrack(s, 0, 0, "", ans);

        return ans;
    }
};