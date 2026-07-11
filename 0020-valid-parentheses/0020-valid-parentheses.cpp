class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Check closing brackets
            else {

                // No matching opening bracket
                if (st.empty())
                    return false;

                char top = st.top();

                // Matching pair
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.empty();
    }
};