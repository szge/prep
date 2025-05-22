class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        endOfWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string word, TrieNode* curr) {
        if (word.size() == 0) return (curr != nullptr && curr->endOfWord);
        char l = word[0];
        if (l == '.') {
            for (TrieNode* child : curr->children) {
                if (child != nullptr) {
                    if (dfs(word.substr(1), child)) return true;
                }
            }
            return false;
        } else {
            int idx = l - 'a';
            if (curr->children[idx] == nullptr) return false;
            return dfs(word.substr(1), curr->children[idx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char l : word) {
            int idx = l - 'a';
            if (curr->children[idx] == nullptr) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        return dfs(word, root);
    }
};
