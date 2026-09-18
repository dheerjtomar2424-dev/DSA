class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;
        
        path += to_string(node->val);
        
        // If it's a leaf node, add the complete path to result
        if (!node->left && !node->right) {
            paths.push_back(path);
            return;
        }
        
        // Otherwise, continue DFS down both subtrees with separator
        path += "->";
        if (node->left) dfs(node->left, path, paths);
        if (node->right) dfs(node->right, path, paths);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }
};