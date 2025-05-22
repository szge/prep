/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> clones;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (clones.count(node) > 0) return clones[node];
        Node* new_node = new Node(node->val);
        clones[node] = new_node;
        for (auto n : node->neighbors) new_node->neighbors.push_back(cloneGraph(n));
        return new_node;
    }
};
