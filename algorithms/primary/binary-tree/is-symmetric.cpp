// 对称二叉树
/* 给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 对比对应的子节点的值以及递归子树
 class Solution {
 private:
     bool validate(TreeNode* left, TreeNode* right) {
         if (left == NULL && right == NULL) return true;
         if (left == NULL ^ right == NULL) return false; // 异或操作, 如果左树或右树中有一个是 NULL 则 return false
         if (left->val != right->val) return false;
         return validate(left->right, right->left) && validate(left->left, right->right);
     }
 public:
     bool isSymmetric(TreeNode* root) {
         if (root == NULL) return true;
         return validate(root->left, root->right);
     }
 };
