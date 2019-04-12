/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        if (left && right) {
            if (left->val == right->val) {
                return symmetric(left->left, right->right) && symmetric(left->right, right->left);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return symmetric(root->left, root->right);
    }
};