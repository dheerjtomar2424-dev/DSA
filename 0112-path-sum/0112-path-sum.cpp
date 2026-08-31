class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (!root)
            return false;

        // Leaf node
        if (!root->left && !root->right)
            return root->val == targetSum;

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};