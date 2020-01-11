//  验证回文字符串
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
*/

class Solution {
private:
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    bool isUppercase(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool isLowercase(char c) {
        return c >= 'a' && c <= 'z';
    }
    bool isValid(char c) {
        return isNumber(c) || isUppercase(c) || isLowercase(c);
    }
public:
    bool isPalindrome(string s) {

        const int gap = 32;

        int i = 0;
        int j = (int)s.size() - 1;

        while (i < j) {
            while (!isValid(s[i])) {
                if (i > j) return true;
                i++;
            }
            while (!isValid(s[j])) {
                if (i > j) return true;
                j--;
            }

            if (isNumber(s[i]) || isNumber(s[j])) {
                if (s[i] != s[j]) {
                    return false;
                }
            } else if (s[i] != s[j] && s[i] != (s[j] + gap) && s[j] != (s[i] + gap)) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
