/**
中序遍历二叉树: 在二叉树中，中序遍历首先遍历左子树，然后访问根结点，最后遍历右子树。
给定一个二叉树，返回它的中序 遍历。
*/

// 递归
class Solution {
private:
    vector<int> result;
    void mark(TreeNode* node) {
        result.push_back(node->val);
    }
    void travel(TreeNode* root) {
        if (root == NULL) return;
        if (root->left != NULL) {
            travel(root->left);
        }
        mark(root);
        if (root->right != NULL) {
            travel(root->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        result = vector<int>();
        travel(root);
        return result;
    }
};
