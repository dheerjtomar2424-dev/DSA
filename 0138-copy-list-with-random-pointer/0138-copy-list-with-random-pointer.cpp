class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head)
            return nullptr;

        // 1. Create copy nodes next to original nodes
        Node* curr = head;

        while (curr) {

            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // 2. Set random pointers
        curr = head;

        while (curr) {

            if (curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // 3. Separate original and copied lists
        curr = head;
        Node* newHead = head->next;

        while (curr) {

            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return newHead;
    }
};