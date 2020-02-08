/* 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。*/

// 动态规划的问题，爬到第i级有两种情况，爬两级和爬一级，
// 所以 steps[i] = steps[i-1] + steps[i-2]
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int steps[n + 1];
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n];
    }
};

// 采用 Fibonacci 数列计算，空间复杂度 O(1)
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        int third;
        for (int i = 2; i < n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return second;

    }
};
