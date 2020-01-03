
// 从排序数组中删除重复项

// 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。


#include <iostream>
#include <vector>

// 遍历到每个值时都与之前的所有值做比较，如有相同，则 erase 当前值，时间复杂度：O(n²)
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;

        int length = (int)nums.size();

        bool isDuplicated = false;

        while (i < length) {
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    nums.erase(nums.begin() + i);
                    length--;
                    isDuplicated = true;
                    break;
                }

                isDuplicated = false;
            }

            if (!isDuplicated) i++;

        }

        return length;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> num({1,1,2,2,0,0,1,1,3,3,3,3,3,3,4});
    Solution hello;
    hello.removeDuplicates(num);

    for (int i = 0; i < num.size(); i++) {
        std::cout << num[i] << std::endl;
    }

    return 0;
}
