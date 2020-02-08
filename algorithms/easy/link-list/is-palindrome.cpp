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

// 递归方法，妙啊！
class Solution {
private:
    ListNode* frontPointer;
private:
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != NULL) {
            // 递归触底，反弹
            if (!recursivelyCheck(currentNode->next)) return false;
            // 触底之后，把递归的返回值和正向值对比
            if (currentNode->val != frontPointer->val) return false;
            // 正向值指向下一位
            frontPointer = frontPointer->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
};
