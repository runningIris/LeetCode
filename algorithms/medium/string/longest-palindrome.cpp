//  最长回文子串
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 中心扩展算法
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)O(1)。
class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return { left + 1, right - 1 };
    }
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int size = (int)s.size();

        for (int i = 0; i < size; ++i) {
            pair<int, int> pair1 = expandAroundCenter(s, i, i);
            pair<int, int> pair2 = expandAroundCenter(s, i, i+1);

            int left1 = get<0>(pair1);
            int right1 = get<1>(pair1);

            int left2 = get<0>(pair2);
            int right2 = get<1>(pair2);

            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
