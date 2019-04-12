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
    void addNode(vector<int>& nums, int l, int r, TreeNode *root) {
        if (l > r)
            return;
        if (l == r) {
            if (nums[l] < root->val)
                root->left = new TreeNode(nums[l]);
            else
                root->right = new TreeNode(nums[l]);
            return;
        }
                  
        int middle = (l+r) / 2;
        if (nums[r] < root->val) {
            root->left = new TreeNode(nums[middle]);
            addNode(nums, l, middle-1, root->left);
            addNode(nums, middle+1, r, root->left);
        } else {
            root->right = new TreeNode(nums[middle]);
            addNode(nums, l, middle-1, root->right);
            addNode(nums, middle+1, r, root->right);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        int ll = nums.size() - 1;
        TreeNode *root = new TreeNode(nums[ll/2]);
        addNode(nums, 0, ll/2 - 1, root);
        addNode(nums, ll/2 +1, ll, root);
        return root;
    }
};