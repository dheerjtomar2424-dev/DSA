class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();

            if (--k == 0) {
                return curr->val;
            }

            curr = curr->right;
        }

        return -1;
    }
};