// 删除链表的倒数第N个节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;

        ListNode* current = head;
        ListNode* slow = head;

        if (n == 1) {
            if (current -> next == NULL) {
                head = NULL;
            } else {
                while (current -> next -> next != NULL) {
                    current = current -> next;
                }
                current -> next = NULL;
            }
        } else {
            while (i < n) {
                current = current -> next;
                i++;
            }

            while (current != NULL) {
                current = current -> next;
                slow = slow -> next;
            }

            if (slow -> next != NULL) {
                slow -> val = slow -> next -> val;
                slow -> next = slow -> next -> next;
            }
        }


        return head;
    }
};
