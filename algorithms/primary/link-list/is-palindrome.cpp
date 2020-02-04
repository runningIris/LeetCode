// 回文链表

// 栈方法对比
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return 1;
        stack<int> container;
        int count = 0;
        ListNode* current = head;
        while(current!=NULL) {
            container.push(current->val);
            count++;
            current = current->next;
        }

        for(int i = 0; i < count/2; i++) {
            if (container.top() != head->val) return 0;
            container.pop();
            head = head->next;
        }
        return 1;
    }
};
