class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;

        while (curr) {

            if (curr->left) {

                // Find the rightmost node of left subtree
                TreeNode* prev = curr->left;

                while (prev->right) {
                    prev = prev->right;
                }

                // Connect original right subtree
                prev->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};