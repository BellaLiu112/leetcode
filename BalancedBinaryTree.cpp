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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (l - r < 2 && l-r > -2 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        else
            return false;
       
    }
};