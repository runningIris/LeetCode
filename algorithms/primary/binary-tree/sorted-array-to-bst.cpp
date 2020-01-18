/*将有序数组转换为二叉搜索树

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
 */

// 采用二分法不断把已排序的数组分下去
class Solution {
private:
    TreeNode* dfs(vector<int>& nums, int lo, int hi) {
        if (lo == hi - 1) {
            TreeNode* node = new TreeNode(nums[hi]);
            TreeNode* left = new TreeNode(nums[lo]);
            node->left = left;
            return node;
        }

        if (lo == hi) return new TreeNode(nums[lo]);

        int mid = (lo + hi)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, lo, mid-1);
        node->right = dfs(nums, mid+1, hi);
        return node;

    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = (int)nums.size();
        if (size < 1) return NULL;
        return dfs(nums, 0, size-1);
    }
};
