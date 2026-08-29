class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        while (head) {

            if (head->val < x) {
                less->next = head;
                less = less->next;
            }
            else {
                greater->next = head;
                greater = greater->next;
            }

            head = head->next;
        }

        // End the greater/equal list
        greater->next = nullptr;

        // Connect both lists
        less->next = greaterDummy.next;

        return lessDummy.next;
    }
};