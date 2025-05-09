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
    // we know the smallest integer is the left-most node in the tree.
    // a brute-force solution involves flattening the tree and picking the k-th element.
    // this is o(n) time and space.
    // attempt 1:
    // vector<int> elements;
    // void dfs(TreeNode* root) {
    //     if (root == nullptr) return;
    //     dfs(root->left);
    //     elements.push_back(root->val);
    //     dfs(root->right);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     dfs(root);
    //     return elements[k - 1];
    // }
    // is there a better solution?
    // we can count the number of nodes in the left subtree. if it's k-1, then root is the kth smallest.
    // attempt 2:
    void dfs(TreeNode* root, int& k, int& sol) {
        if (root == nullptr) return;
        dfs(root->left, k, sol);
        k -= 1;
        if (k == 0) {
            sol = root->val;
        } else {
            dfs(root->right, k, sol);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int sol = 0;
        dfs(root, k, sol);
        return sol;
    }
};
