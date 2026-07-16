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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // If both nodes are smaller, go left
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // If both nodes are greater, go right
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // Split point is the LCA
        return root;
    }
};