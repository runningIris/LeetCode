/**
奇偶链表
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        bool isOdd = true;
        ListNode* even = NULL;
        ListNode* evenHead = NULL;
        ListNode* copy = head;
        ListNode* prev = NULL;
        while (copy != NULL) {
            if (!isOdd) {
                if (even == NULL) {
                    even = copy;
                    evenHead = copy;
                } else {
                    even->next = copy;
                    even = even->next;
                }
                prev->next = copy->next;
            } else {
                prev = copy;
            }
            isOdd = !isOdd;

            copy = copy->next;
        }
        if (prev != NULL) prev->next = evenHead;
        if (even != NULL) even->next = NULL;
        return head;
    }
};
