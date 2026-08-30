class Solution {
public:
    unordered_map<int, int> pos;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {

        if (left > right)
            return nullptr;

        // Current postorder value is the root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        // Build RIGHT first
        root->right = build(postorder, mid + 1, right);

        // Then build LEFT
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        postIndex = n - 1;

        return build(postorder, 0, n - 1);
    }
};