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
public:
    // int height(TreeNode* node) {
    //     if (node == nullptr) return 0;
    //     return max(height(node->left), height(node->right)) + 1;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if (root == nullptr) return 0;
    //     return height(root->left) + height(root->right);
    // }
    // the above gives the solution for a particular node,
    // but the largest solution could be somewhere else in the tree (not the node).
    // to address this we just need to keep track of the maximum

    int height(TreeNode* node, int& answer) {
        if (node == nullptr) return 0;
        int left_height = height(node->left, answer);
        int right_height = height(node->right, answer);
        answer = max(answer, left_height + right_height);
        return max(left_height, right_height) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        height(root, answer);
        return answer;
    }
};
