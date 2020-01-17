// 环形链表
// 给定一个链表，判断链表中是否有环。

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针: 慢指针每次走一步，快指针每次走两步，如果有环，快指针则会再度与慢指针相遇
        if (head == NULL || head->next == NULL) return false;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != slow) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }
};
