class Solution {
private:
    void dfs(vector<vector<char>>& board, string& word, pair<int, int>& curr_pos, bool& succ) {
        int x = curr_pos.first, y = curr_pos.second;
        if (word == "" || word.size() == 1 && board[y][x] == word[0] || succ) {
            succ = true;
            return;
        }
        if (board[y][x] != word[0]) return;
        char og_char = board[y][x];
        board[y][x] = 'n';
        string new_word = word.substr(1);
        if (x > 0) dfs(board, new_word, make_pair(x - 1, y), succ);
        if (x < board[0].size() - 1) dfs(board, new_word, make_pair(x + 1, y), succ);
        if (y > 0) dfs(board, new_word, make_pair(x, y - 1), succ);
        if (y < board.size() - 1) dfs(board, new_word, make_pair(x, y + 1), succ);
        board[y][x] = og_char;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        bool succ = false;
        for (int y = 0; y < board.size() && !succ; y++) {
            for (int x = 0; x < board[0].size() && !succ; x++) {
                dfs(board, word, make_pair(x, y), succ);
            }
        }
        return succ;
    }
};
