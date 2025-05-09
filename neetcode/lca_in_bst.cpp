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
    // I think this works but the way NeetCode sets up the binsearch trees is bad.
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     unordered_set<TreeNode*> nodes;
    //     TreeNode* root_cp = root;
    //     while (root_cp != nullptr) {
    //         nodes.insert(root_cp);
    //         cout << root_cp;
    //         root_cp = (p->val <= root_cp->val) ? root_cp->left : root_cp->right;
    //     }

    //     TreeNode* lca = root;
    //     root_cp = root;
    //     while (root_cp != nullptr) {
    //         if (nodes.count(root_cp) > 0) lca = root_cp;
    //         root_cp = (q->val <= root_cp->val) ? root_cp->left : root_cp->right;
    //     }
    //     return lca;
    // }

    // attempt 2: recursion; o(h) time and o(h) size
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     // root is the least common ancestor if root is between p and q. consider cases where p < q and q < p
    //     // if (root == nullptr || root == p || root == q || (p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val)) return root;
    //     if (root == nullptr || p == nullptr || q == nullptr || root->val == p->val || root->val == q->val) return root;
    //     if (p->val <= root->val && q->val <= root->val) return lowestCommonAncestor(root->left, p, q);
    //     if (p->val >= root->val && q->val >= root->val) return lowestCommonAncestor(root->right, p, q);
    //     return root;
    // }
};
