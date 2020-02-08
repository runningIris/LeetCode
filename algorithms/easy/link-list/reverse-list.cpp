// 反转链表

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;

        while(current != NULL) {
            ListNode* tmp = current -> next;
            current -> next = prev;
            prev = current;
            current = tmp;
        }

        return prev;
    }
};

// 递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;

        ListNode* p = reverseList(head -> next);

        head -> next -> next = head;
        head -> next = NULL;
        return p;
    }
};
