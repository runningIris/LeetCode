/**
给定一个整数，写一个函数来判断它是否是 3 的幂次方。
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        double val = log((double)n) / log((double)3);
        return val == (double)(int)val;
    }
};

// 存在精度问题 log3(243) = 4.9999999, 故而不通过测试

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return 0;
        double val = log((double)n) / log((double)3);
        double accuracy = 0.00000000000001;
        return val - (double)(int)(val + accuracy) < accuracy;
    }
};
