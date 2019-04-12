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
    void 
    levelOrder(vector<vector<int>> &v, TreeNode *root, int currentLevel) 
    {
        if (!root)
            return;
        
        if (v.empty() || v.size() < currentLevel + 1)
            v.push_back(vector<int>());
        v[currentLevel].push_back(root->val);
        
        if (root->left)
            levelOrder(v, root->left, currentLevel+1); 
        if (root->right)
            levelOrder(v, root->right, currentLevel+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        int currentLevel = 0;
        levelOrder(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};