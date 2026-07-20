class Solution {
public:

    bool isPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }

    void getallpairs(string s, vector<string>& partitions, vector<vector<string>>& ans) {

        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (isPalindrome(part)) {
                partitions.push_back(part);

                getallpairs(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getallpairs(s, partitions, ans);

        return ans;
    }
};