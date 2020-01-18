/*
验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// 递归，跟节点的值范围是(INT64_MIN, INT64_MAX)
class Solution {
public:
   bool isValidBST(TreeNode* root) {
       return validate(root, INT64_MIN, INT64_MAX);
   }
   bool validate(TreeNode* root, long int min, long int max) {
       if (root == NULL) return true;
       int val = root->val;
       if (val >= max || val <= min) return false;
       return validate(root->left, min, val) && validate(root->right, val, max);
   }
};
