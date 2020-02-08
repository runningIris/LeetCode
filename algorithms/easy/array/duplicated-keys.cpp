
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

// 使用 unordered_map 实现

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        unordered_map<int, int> map;
        int i = 0;

        while (i < size) {
            int current = nums[i];
            if (!map[current]) {
                map[current] = 1;
                i++;
            } else {
                nums.erase(nums.begin() + i);
                size--;
            }
        }
        return size;
    }
};

// 注意题目要求，是“排序数组”
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        int i = 1;

        while (i < size) {
            if (nums[i-1] == nums[i]) {
                nums.erase(nums.begin() + i);
                size--;
            } else {
                i++;
            }
        }
        return size;
    }
};
