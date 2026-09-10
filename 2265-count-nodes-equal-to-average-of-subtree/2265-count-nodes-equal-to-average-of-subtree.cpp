class Solution {
    int matchingCount = 0;

    // Returns pair<subtree_sum, subtree_node_count>
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int totalSum = leftSum + rightSum + node->val;
        int totalCount = leftCount + rightCount + 1;

        if (totalSum / totalCount == node->val) {
            matchingCount++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        matchingCount = 0;
        dfs(root);
        return matchingCount;
    }
};