class Solution {
public:
    ListNode* curr;

    TreeNode* build(int left, int right) {

        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        // Build left subtree first
        TreeNode* leftTree = build(left, mid - 1);

        // Current list node becomes root
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        // Build right subtree
        TreeNode* rightTree = build(mid + 1, right);

        root->left = leftTree;
        root->right = rightTree;

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        int n = 0;

        for (ListNode* temp = head; temp; temp = temp->next)
            n++;

        curr = head;

        return build(0, n - 1);
    }
};