class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if (list1 != nullptr) {
            curr->next = list1;
        }
        else {
            curr->next = list2;
        }

        return dummy->next;
    }


    ListNode* merge(vector<ListNode*>& lists, int left, int right) {

        if (left > right) {
            return nullptr;
        }

        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;

        ListNode* list1 = merge(lists, left, mid);
        ListNode* list2 = merge(lists, mid + 1, right);

        return mergeTwoLists(list1, list2);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) {
            return nullptr;
        }

        return merge(lists, 0, lists.size() - 1);
    }
};