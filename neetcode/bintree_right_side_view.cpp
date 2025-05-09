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
    // attempt 1: this didn't work because the right side visible node on the next level
    // is not necessarily a child of the current node.
// private:
//     vector<int> res;
// public:
//     void rightSideViewHelper(TreeNode* root) {
//         if (root == nullptr) return;
//         res.push_back(root->val);
//         if (root->right != nullptr) {
//             rightSideViewHelper(root->right);
//         } else {
//             rightSideViewHelper(root->left);
//         }
//     }

//     vector<int> rightSideView(TreeNode* root) {
//         rightSideViewHelper(root);
//         return res;
//     }
    // attempt 2: just get level-order traversal and print ends of each level.
// private:
//     void levelOrderHelper(vector<vector<int>>& output, TreeNode* root, int depth) {
//         if (root == nullptr) return;
//         if (output.size() <= depth) output.push_back({});
//         output[depth].push_back(root->val);
//         levelOrderHelper(output, root->left, depth + 1);
//         levelOrderHelper(output, root->right, depth + 1);
//     }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> output;
//         levelOrderHelper(output, root, 0);
//         return output;
//     }
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<vector<int>> level_order = levelOrder(root);
//         vector<int> sol;
//         for (int i = 0; i < level_order.size(); i++) {
//             int len = level_order[i].size();
//             sol.push_back(level_order[i][len - 1]);
//         }
//         return sol;
//     }

    // attempt 3: straight dfs (optimal)
private:
    vector<int> sol;
    void rightSideViewHelper(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (sol.size() == depth) sol.push_back(root->val);
        rightSideViewHelper(root->right, depth + 1);
        rightSideViewHelper(root->left, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        rightSideViewHelper(root, 0);
        return sol;
    }
};
