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
    int num_good_nodes = 0;
    void goodNodesHelper(TreeNode* root, int curr_max) {
        if (root == nullptr) return;
        int curr_max_cp = curr_max;
        if (root->val >= curr_max) {
            num_good_nodes += 1;
            curr_max_cp = root->val;
        }
        goodNodesHelper(root->left, curr_max_cp);
        goodNodesHelper(root->right, curr_max_cp);
    }

public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        goodNodesHelper(root, -9999999); // val is between -100 and 100 so this is fine
        return num_good_nodes;
    }
};
