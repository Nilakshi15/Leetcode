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
    int ans = 0;
    int count = 0;

    void inorder(TreeNode* root, int k) {

        if (root == NULL)
            return;

        // Visit left subtree
        inorder(root->left, k);

        // Current node
        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        // Visit right subtree
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {

        inorder(root, k);
        return ans;
    }
};