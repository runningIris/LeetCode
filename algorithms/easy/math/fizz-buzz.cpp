/**
写一个程序，输出从 1 到 n 数字的字符串表示。
1. 如果 n 是3的倍数，输出“Fizz”；
2. 如果 n 是5的倍数，输出“Buzz”；
3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0) {
                if (i % 3 == 0) {
                    result.push_back("FizzBuzz");
                } else {
                    result.push_back("Buzz");
                }
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};
