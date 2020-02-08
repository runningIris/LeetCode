// 二叉树的最大深度

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int depth(TreeNode* root, int accum) {
        if (root == NULL) return accum;
        if (root->left == NULL && root->right == NULL) return accum + 1;

        int left = depth(root->left, accum + 1);
        int right = depth(root->right, accum + 1);

        return left > right ? left : right;
    }
public:
    int maxDepth(TreeNode* root) {
        return depth(root, 0);
    }
};
