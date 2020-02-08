// 最长公共前缀
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

说明:
所有输入只包含小写字母 a-z 。
*/

class Solution {
private:
    int findLongestStrLen(vector<string>& strs) {
        int max = 0;
        for (int i = 0; i < (int)strs.size(); i++) {
            int size = (int)strs[i].size();
            if (size > max) {
                max = size;
            }
        }
        return max;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;

        int size = (int)strs.size();
        int len = findLongestStrLen(strs);

        if (size < 1) {
            return "";
        }

        while (i < len) {
            char c = strs[0][i];
            int k;
            for (k = 1; k < size; k++) {
                if (strs[k][i] != c) {
                    break;
                }
            }
            if (k < size) break;

            i++;
        }

        return strs[0].substr(0, i);
    }
};
