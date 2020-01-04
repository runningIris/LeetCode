// 加一

/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = (int)digits.size() - 1;
        bool shouldAdvanceOne = true;
        while (i >= 0 && shouldAdvanceOne) {
            if (digits[i] == 9) {
                digits[i] = 0;
                shouldAdvanceOne = true;
            } else {
                digits[i] += 1;
                shouldAdvanceOne = false;
            }
            i--;
        }
        if (shouldAdvanceOne) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
