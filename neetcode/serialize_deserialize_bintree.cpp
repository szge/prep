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

class Codec {
public:
    // I think my solution is much cleaner than the given solution that uses way more helper functions.
    // TIL that you can't in-order serialize since multiple trees can serialize to the same thing.
    // /**
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

class Codec {
public:
    // I think my solution is much cleaner than the given solution that uses way more helper functions.
    // TIL that you can't in-order serialize since multiple trees can serialize to the same thing.
    // https://www.baeldung.com/cs/binary-tree-serialize-deserialize

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // dfs serialize
        if (root == nullptr) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize_helper(data);
    }

private:
    TreeNode* deserialize_helper(string& data) {
        if (data.empty()) return nullptr;
        if (data[0] == 'N') {
            data = data.substr(2);
            return nullptr;
        }
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos + 1);
        TreeNode* node = new TreeNode(val);
        node->left = deserialize_helper(data);
        node->right = deserialize_helper(data);
        return node;
    }
};


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // dfs serialize
        if (root == nullptr) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize_helper(data);
    }

private:
    TreeNode* deserialize_helper(string& data) {
        if (data.empty()) return nullptr;
        if (data[0] == 'N') {
            data = data.substr(2);
            return nullptr;
        }
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos + 1);
        TreeNode* node = new TreeNode(val);
        node->left = deserialize_helper(data);
        node->right = deserialize_helper(data);
        return node;
    }
};
