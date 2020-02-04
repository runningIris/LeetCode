/**
汉明距离
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.
 */

// 解题思路：将一个字符串变换成另外一个字符串所需要替换的字符个数。
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n % 2 == 1) {
                count += 1;
            }
            n = n / 2;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        return hammingWeight(x ^ y);
    }
};
