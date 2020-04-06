/**
二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/

// 得出正常顺序的答案后，把双数的数组反序
class Solution {
private:
    vector<vector<int>> result;
    void traversal(TreeNode* root, int layer) {
        if (root == NULL) return;
        if (layer >= (int)result.size()) {
            result.push_back(vector<int>({root->val}));
        } else {
            result[layer].push_back(root->val);
        }
        traversal(root->left, layer+1);
        traversal(root->right, layer+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traversal(root, 0);
        for (int i = 0; i < (int)result.size(); i++) {
            if (i % 2 == 1) {
                int size = (int)result[i].size();
                for (int j = 0; j < size / 2; j++) {
                    int tmp = result[i][j];
                    result[i][j] = result[i][size-1-j];
                    result[i][size-1-j] = tmp;
                }
            }
        }
        return result;
    }
};
