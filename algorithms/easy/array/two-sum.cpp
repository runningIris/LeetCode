// 两数之和
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

// 暴力: 时间 O(n²), 空间 O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    vector<int> v({i, j});
                    return v;
                }
            }
        }
        throw 20;
    }
};

// 一遍哈希表实现 时间 O(n), 空间 O(n)
// 如果目标值已在 map 中, 则返回两个值组成的数组, 否则, 记录下当前值进 map 和 index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        unordered_map<int, int> index;
        int size = (int)nums.size();

        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];
            if (map[complement] != 1) {
                map[nums[i]] = 1;
                index[nums[i]] = i;
            } else {
                return vector<int>({i, index[complement]});
            }
        }
        throw "No matching numbers.";
    }
};
