class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (true) {

            // Find kth node
            ListNode* kth = prev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* curr = prev->next;
            ListNode* before = groupNext;

            while (curr != groupNext) {

                ListNode* next = curr->next;

                curr->next = before;
                before = curr;
                curr = next;
            }

            // Connect previous part to reversed group
            ListNode* oldFirst = prev->next;

            prev->next = kth;
            prev = oldFirst;
        }
    }
};