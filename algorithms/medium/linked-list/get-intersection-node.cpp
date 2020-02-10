/**
相交链表
编写一个程序，找到两个单链表相交的起始节点。
*/

// 注意，直接对比指针的地址才能保证是同一个节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int i = 0;
        int j = 0;
        ListNode* A = headA;
        ListNode* B = headB;
        while (A != NULL) {
            A = A->next;
            i++;
        }
        while (B != NULL) {
            B = B->next;
            j++;
        }
        int k = i - j;

        if (k > 0) {
            while (k > 0) {
                headA = headA->next;
                k--;
            }
        } else {
            while (k < 0) {
                headB = headB->next;
                k++;
            }
        }
        ListNode* result = NULL;
        while (headA != NULL) {
            if (headA != headB) result=NULL;
            else if (result == NULL) result = headA;
            headA = headA->next;
            headB = headB->next;
        }
        return result;
    }
};
