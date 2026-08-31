class Solution {
public:
    Node* connect(Node* root) {

        if (!root)
            return nullptr;

        Node* level = root;

        while (level->left) {

            Node* curr = level;

            while (curr) {

                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next parent's left child
                if (curr->next)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }

            level = level->left;
        }

        return root;
    }
};