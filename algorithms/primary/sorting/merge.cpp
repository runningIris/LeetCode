/* 合并两个有序数组
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/

// 双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;;
        int i;
        for (i = 0; i < m; i++) {
            tmp.push_back(nums1[i]);
        }
        int a = 0, b = 0;
        i = 0;
        while (a < m || b < n) {
            if (a < m && b < n) {
                if (tmp[a] < nums2[b]) {
                    nums1[i] = tmp[a];
                    a++;
                } else {
                    nums1[i] = nums2[b];
                    b++;
                }
            } else if (a < m) {
                nums1[i] = tmp[a];
                a++;
            } else {
                nums1[i] = nums2[b];
                b++;
            }
            i++;
        }
    }
};
