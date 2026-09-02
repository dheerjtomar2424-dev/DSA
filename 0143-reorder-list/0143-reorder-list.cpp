class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode *second = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;
        while (second) {
            ListNode *next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // 3. Merge two halves
        ListNode *first = head;
        second = prev;

        while (second) {
            ListNode *next1 = first->next;
            ListNode *next2 = second->next;

            first->next = second;
            second->next = next1;

            first = next1;
            second = next2;
        }
    }
};