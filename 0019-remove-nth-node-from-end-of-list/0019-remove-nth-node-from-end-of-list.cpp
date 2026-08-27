class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n+1 positions
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the node
        slow->next = slow->next->next;

        return dummy->next;
    }
};