// 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 说明: 必须在原数组上操作，不能拷贝额外的数组。尽量减少操作次数。

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int i = 0;
        int len = (int)nums.size();
        while (i < len) {
            if (nums[i] == 0) {
                nums.push_back(0);
                nums.erase(nums.begin() + i);
                len--;
            } else {
                i++;
            }
        }
        return nums;
    }
};
