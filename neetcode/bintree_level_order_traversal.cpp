/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void levelOrderHelper(vector<vector<int>>& output, TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (output.size() <= depth) output.push_back({});
        output[depth].push_back(root->val);
        levelOrderHelper(output, root->left, depth + 1);
        levelOrderHelper(output, root->right, depth + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        levelOrderHelper(output, root, 0);
        return output;
    }
};
