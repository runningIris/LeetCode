// 外观数列
/*
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

注意：整数序列中的每一项将表示为一个字符串。
*/

/*
1
2 描述的是1，是一个1，也就是11
3 描述的是11，是两个1，也就是21
4 描述的是21，是一个2一个1，也就是12-11
5 描述的是1211, 是一个1，一个2，两个1，也就是11-12-21
6 描述的是111221，是三个1，两个2，一个1，也就是31-22-11
7 描述的是312211，是一个3一个1两个2两个1，也即是13-11-22-21
以此类推
*/

class Solution {
private:
    string say(string count) {
        int size = (int)count.size();

        if (size == 1) return to_string(1) + count;
        int n = 1;
        int i = 0;
        string result = "";
        while (i < size-1) {
            if (count[i] != count[i+1]) {
                result += to_string(n) + count[i];

                if (i == size - 2) {
                    result += to_string(1) + count[i + 1];
                } else {
                    n = 1;
                }

            } else {
                n++;

                if (i == size - 2) {
                    result += to_string(n) + count[i + 1];
                }
            }
            i++;
        }

        return result;
    }
public:
    string countAndSay(int n) {
        string count = "1";
        for (int i = 1; i < n; i++) {
            count = say(count);
            cout << "count: " << count << endl;
        }
        return count;
    }
};
