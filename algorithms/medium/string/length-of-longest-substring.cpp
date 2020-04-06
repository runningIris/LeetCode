// 无重复字符的最长子串
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = (int)s.size();
        int i = 0;
        int max = 0;

        for (int j = 0; j < size; j++) {
            for (int k = i; k < j; k++) {
                if (s[j] == s[k]) {
                    i = k + 1;
                    break;
                }
            }
            int tmp = j - i + 1;
            if (tmp > max) max = tmp;
        }
        return max;
    }
};
