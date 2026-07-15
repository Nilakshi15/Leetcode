/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> index; // Stores inorder value -> index
    int postIdx;                   // Current index in postorder

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        // No nodes left in this subtree
        if (left > right)
            return NULL;

        // Last element in postorder is the root
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int mid = index[rootVal];

        // Build right subtree first (because postorder is Left Right Root)
        root->right = build(inorder, postorder, mid + 1, right);

        // Build left subtree
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Store inorder indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }

        postIdx = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};