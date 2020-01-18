// 二叉树的层次遍历

/*给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* current, int depth, vector<vector<int>>& arr) {
        if (current == NULL) return;
        if (depth >= (int)arr.size()) {
            arr.push_back(vector<int> {});
        }
        arr[depth].push_back(current->val);
        dfs(current->left, depth+1, arr);
        dfs(current->right, depth+1, arr);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        dfs(root, 0, arr);
        return arr;
    }
};
