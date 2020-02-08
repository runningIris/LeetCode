/*
缺失数字
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
*/

// 哈希映射 两次遍历
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num: nums) {
            m[num] = 1;
        }
        for (int i = 0; i <= (int)nums.size(); i++) {
            if (m[i] != 1) return i;
        }
        return -1;
    }
};

// 或与运算
// 相同的数都两两配对消除了，剩下就是缺少的
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            result ^= i;
            result ^= nums[i];
        }

        return result ^ size;
    }
};

// 0->n 的总和减去数组之和
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = (int)nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        return size * (size + 1) / 2 - sum;
    }
};
