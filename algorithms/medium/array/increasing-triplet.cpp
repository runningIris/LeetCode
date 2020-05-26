// 递增的三元子序列
// 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)
/*
 * 新建两个变量 small 和 mid
 * 接着，我们遍历数组，每遇到一个数字，我们将它和 small 和 mid 相比
 * 若小于等于 small ，则替换 small；
 * 否则，若小于等于 mid，则替换 mid；
 * 否则，若大于 mid，则说明我们找到了长度为 3 的递增数组！
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = 0;
        int size = (int)nums.size();
        if (size < 3) return false;
        int small = nums[0];
        int mid = INT_MAX;
        while (i < size) {
            if (nums[i] <= small) small = nums[i];
            else if (nums[i] > mid) return true;
            else mid = nums[i];
            i++;
        }
        return false;
    }
};
