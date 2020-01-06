// 整数反转
// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
// 注意:
// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2³¹,  2³¹ − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

// 关键点：
// 1. 在于反转之后的数值超出 int 取值范围的判断和处理（除10来判断）
// 2. 输入值如果超出 int 范围是可以的，只要输出不超出 int 范围, 但超出 int 范围的数会隐式转换为 unsigned int
class Solution {
public:
    int reverse(int x) {
        const bool IS_NEGATIVE = x < 0;
        const long DECIMAL = 10;
        long remainder = 0;
        long quotient = IS_NEGATIVE ? 0 - (long)x : (long)x; // 取 x 的绝对值


        vector<int> arr;

        while(quotient > 0) {
            remainder = quotient % DECIMAL;
            quotient -= remainder;
            quotient /= DECIMAL;
            arr.push_back((int)remainder);
        }

        int result = 0;

        for (int i = (int)arr.size() - 1; i >=0 ; i--) {
            if (result / 10 + arr[i]  * pow(10, (int)arr.size() - i - 2) > INT_MAX / 10) {
                return 0;
            }
            int curr = arr[i]  * pow(10, (int)arr.size() - i - 1);
            result += curr;
        }

        return IS_NEGATIVE ? 0 - result : result;
    }
};
