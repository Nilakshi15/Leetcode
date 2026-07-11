class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {

            // End of a directory name
            if (i == path.size() || path[i] == '/') {

                if (curr == "" || curr == ".") {
                    // Ignore empty and current directory
                }
                else if (curr == "..") {
                    // Go to parent directory
                    if (!st.empty())
                        st.pop();
                }
                else {
                    // Valid directory name
                    st.push(curr);
                }

                curr = "";
            }
            else {
                curr += path[i];
            }
        }

        // Build the answer
        vector<string> dirs;

        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string ans = "";

        for (string dir : dirs)
            ans += "/" + dir;

        return ans.empty() ? "/" : ans;
    }
};