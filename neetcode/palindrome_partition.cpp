#include <string>
#include <vector>
#include <iostream>

class Solution {
private:
    bool isPalindrome(std::string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }

    void dfs(std::string& s, std::vector<std::string>& curr, int& curr_idx, std::vector<std::vector<std::string>>& sol) {
        // this fn is basically: gimme all the palindrome partitions from curr_index to s.size()
        if (curr_idx == s.size()) {
            sol.push_back(curr);
            return;
        }

        // we need to go all the way up to s.size() to make sure that we reach the base case
        for (int i = curr_idx + 1; i <= s.size(); i++) {
            std::string p = s.substr(curr_idx, i - curr_idx);
            if (isPalindrome(p)) {
                curr.push_back(p);
                for (std::string& c : curr) std::cout << c << " ";
                std::cout << std::endl;
                dfs(s, curr, i, sol);
                curr.pop_back();
            }
        }
    }
    // example: "aab"
    // curr_idx = 0, i = 1, "a" is palindrome, push "a", recurse
    // curr_idx = 1, i = 2, "a" is palindrome, push "a", recurse
    // curr_idx = 2 = s.size() - 1, push "b", push curr, backtrack

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> sol;
        std::vector<std::string> curr;
        int curr_index = 0;
        dfs(s, curr, curr_index, sol);
        return sol;
    }
};

int main() {
    Solution solution;
    std::string s = "aab";
    auto sols = solution.partition(s);
    std::cout << "Solutions:" << std::endl;
    for (auto sol : sols) {
        for (auto st : sol) std::cout << st << " ";
        std::cout << std::endl;
    }
}