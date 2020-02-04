/**
 颠倒二进制位
 颠倒给定的 32 位无符号整数的二进制位。
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            // 左移一位给挪出位置
            result <<= 1;
            // 压入 n 的最后一位
            result += n&1;
            // 右移一位
            n >>= 1;
        }
        return result;
    }
};
