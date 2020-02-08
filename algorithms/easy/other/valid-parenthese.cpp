/**
有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/
class Solution {
public:
    bool isValid(string s) {
        // 映射左右括号
        unordered_map<char, char> m;
        m['['] = ']';
        m['('] = ')';
        m['{'] = '}';

        stack<char> container;
        for (char c : s) {
            // 栈为空时压入第一个元素
            if (container.empty()) {
                container.push(c);
                continue;
            }
            char top = container.top();

            // 如果是左括号则压入栈
            if (m[c]) container.push(c);
            // 如果栈顶元素的右括号不等于当前元素则表示无效
            else if (m[top] != c) return 0;
            // 如果左右括号相碰则湮灭
            else container.pop();
        }
        // 如果最后栈内还有元素未被对对碰消除，则表示无效
        if (!container.empty()) return 0;
        return 1;
    }
};
