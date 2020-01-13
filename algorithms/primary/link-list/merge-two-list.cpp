// 合并两个有序链表

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* current;

        if (!l1) return l2;
        else if (!l2) return l1;
        else if (l1 -> val < l2 -> val) {
            head = l1;
            current = l1;
            l1 = l1 -> next;
        } else {
            head = l2;
            current = l2;
            l2 = l2 -> next;
        }

        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                head -> next = l1;
                l1 = l1 -> next;
            } else {
                head -> next = l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }

        if (l1 != NULL) {
            head -> next = l1;
        }

        if (l2 != NULL) {
            head -> next = l2;
        }

        return current;
    }
};
