class Solution {
public:
    Node* connect(Node* root) {

        Node* curr = root;

        while (curr) {

            Node dummy(0);
            Node* tail = &dummy;

            // Traverse current level using next pointers
            while (curr) {

                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;
            }

            // Move to first node of next level
            curr = dummy.next;
        }

        return root;
    }
};