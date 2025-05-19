class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        endOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char l : word) {
            int idx = l - 'a';
            if (curr->children[idx] == nullptr) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char l : word) {
            int idx = l - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char l : prefix) {
            int idx = l - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
