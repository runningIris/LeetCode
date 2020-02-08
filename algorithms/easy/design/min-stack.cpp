// 最小栈

// Solution 1: 双向链表实现
struct DoubleListNode {
    int val;
    DoubleListNode* next;
    DoubleListNode* prev;
    DoubleListNode(int val): val(val), next(NULL), prev(NULL) {}
};

class MinStack {
private:
    DoubleListNode* head;
    DoubleListNode* tail;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        head = NULL;
        tail = NULL;
    }

    void push(int x) {
        if (tail == NULL) {
            head = new DoubleListNode(x);
            tail = head;
        } else {
            DoubleListNode* tmp = tail;
            tail->next = new DoubleListNode(x);
            tail = tail->next;
            tail->prev = tmp;
        }
    }

    void pop() {
        if (tail == NULL) return;
        else if (tail->prev == NULL) {
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
    }

    int top() {
        return tail->val;
    }

    int getMin() {
        DoubleListNode* current = head;
        int min = current->val;
        current = current->next;
        while (current != NULL) {
            if (current->val < min) {
                min = current->val;
            }
            current = current->next;
        }
        return min;
    }
};

// Solution 2: https://leetcode-cn.com/problems/min-stack/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-38/
// 采用两个栈，一个用来存值，一个用来存最小值
