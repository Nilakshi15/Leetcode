/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeHelper(TreeNode* root, string &s) {

        if (root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;
        serializeHelper(root, s);

        return s;
    }

    TreeNode* deserializeHelper(queue<string>& q) {

        string val = q.front();
        q.pop();

        if (val == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);

        return root;
    }

    TreeNode* deserialize(string data) {

        queue<string> q;
        string temp;

        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        return deserializeHelper(q);
    }
};