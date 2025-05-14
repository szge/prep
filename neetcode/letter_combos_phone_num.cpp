class Solution {
private:
    vector<string> i_to_c = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string& digits, string& curr, int curr_idx, vector<string>& sol) {
        if (curr_idx == digits.size()) {
            sol.push_back(curr);
            return;
        }
        int curr_digit = digits[curr_idx] - '0';
        string& choices = i_to_c[curr_digit];
        for (char c : choices) {
            curr.push_back(c);
            dfs(digits, curr, curr_idx + 1, sol);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        if (digits.size() == 0) return sol;
        string curr;
        dfs(digits, curr, 0, sol);
        return sol;
    }
};
