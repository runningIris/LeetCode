// 两个数组的交集 II
// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode/

/*
说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。

进阶:
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/

// 让 nums1 和 nums2 里的嵌套遍历进行对比，时间复杂度：O(n²)
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            int j = 0;
            while (j < nums2.size()) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + j);
                    break;
                }
                j++;
            }
        }
        return result;
    }
};

// 排过序之后的方法: O(n)
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
               result.push_back(nums1);
               i++;
               j++;
            }
            if (nums1[i] < nums2[j]) {
                i++;
            }

            if (nums1[i] > nums2[j]) {
                j++;
            }
        }
        return result;
    }
};

class Solution3 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> m;
        for (auto n : nums1) {
            ++m[n];
        }
        int k = 0;
        for (auto n : nums2) {
            auto it = m.find(n);
            if (it != end(m) && --it->second >= 0) {
                nums1[k++] = n;
            }
        }
        return vector(begin(nums1), begin(nums1) + k);
    }
};


class Solution4 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        nums1.erase(set_intersection(begin(nums1), end(nums1),
            begin(nums2), end(nums2), begin(nums1)), end(nums1));
        return nums1;
    }

};
