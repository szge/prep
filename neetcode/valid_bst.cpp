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
    // attempt 1: this doesn't work bc e.g. right can be a bst while containing a value smaller than root
    // bool isValidBST(TreeNode* root) {
    //     if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
    //     if (root->left == nullptr) return (root->right->val > root->val);
    //     if (root->right == nullptr) return (root->left->val < root->val);
    //     if (root->left->val >= root->val || root->right->val <= root->val) return false;
    //     return isValidBST(root->left) && isValidBST(root->right);
    // }

    // attempt 2: the following runs into the same issue. dumb me
    // bool bstHelper(TreeNode* root, int parent_min, int parent_max) {
    //     if (root == nullptr) return true;
    //     int new_min = min(parent_min, root->val);
    //     int new_max = max(parent_max, root->val);
    //     if (root->left != nullptr && root->left->val >= new_min) return false;
    //     if (root->right != nullptr && root->right->val <= new_max) return false;
    //     return bstHelper(root->left, new_min, new_max) && bstHelper(root->right, new_min, new_max);
    // }

    // bool isValidBST(TreeNode* root) {
    //     if (root == nullptr) return true;
    //     return bstHelper(root, root->val, root->val);
    // }

    // attempt 3: valid interval. similar idea to above, but actually correct
    bool bstHelper(TreeNode* root, int interval_min, int interval_max) {
        if (root == nullptr) return true;
        if (root->val >= interval_max || root->val <= interval_min) return false;
        return bstHelper(root->left, interval_min, min(interval_max, root->val)) && bstHelper(root->right, max(interval_min, root->val), interval_max);
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return bstHelper(root, -9999, 9999);
    }
};
