// 有效的字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 排序后对比两个字符串是否一致，时间复杂度：O(nlogn)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 使用数组来计数，其中 index = char - 'a'
class Solution {
public:
    bool isAnagram(string s, string t) {
        int i, x[26] = {0}, y[26] = {0};
        for (i = 0; s[i] != '\0'; i++) x[s[i] - 'a']++;
        for (i = 0; t[i] != '\0'; i++) y[t[i] - 'a']++;
        for (i = 0; i < 26; i++) if (x[i] != y[i]) return false;

        return true;
    }
};
