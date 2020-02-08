//  字符串中的第一个唯一字符
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

class Solution {
public:
    int firstUniqChar(string& s) {
        map<char, int> m;
        for(char c: s) {
            if (!m[c]) {
                m[c] = 1;
            } else {
                m[c]++;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 1) return i;
        }

        return -1;
    }
};
