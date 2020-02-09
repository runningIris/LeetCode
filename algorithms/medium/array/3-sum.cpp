/**
三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/

// 参照答案的，不懂如何去重
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = size - 1;
            while (l < r) {
                int value = nums[i] + nums[l] + nums[r];
                if (value < 0) l++;
                else if (value > 0) r--;
                else {
                    result.push_back(vector<int>({nums[i], nums[l], nums[r]}));
                    l++;
                    r--;
                    while (l < r && nums[l-1] == nums[l]) l++;
                    while (l < r && nums[r+1] == nums[r]) r--;
                }
            }
        }
        return result;
    }
};
