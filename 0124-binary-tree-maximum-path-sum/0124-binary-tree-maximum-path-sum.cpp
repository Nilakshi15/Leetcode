/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */
class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Update maximum path
        ans = max(ans, left + right + root->val);

        // Return one-side path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);
        return ans;
    }
};