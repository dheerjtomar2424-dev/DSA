class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {

            // Check if current value is duplicated
            if (curr->next && curr->val == curr->next->val) {

                int value = curr->val;

                // Skip all nodes having this value
                while (curr && curr->val == value) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};